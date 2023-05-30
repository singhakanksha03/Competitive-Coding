/*
You are given an undirected weighted graph G with n vertices. And Q queries, each query consists of two integers a and b and you have print the distance of shortest path between a and b.
Note: If there is no path between a and b print 10^9
Input Format:
First line of Input will contain T(number of test cases), each test case follows as.
Line1: contains two space-separated integers N and M denoting the number of vertex and edge in graph.
Next M line contain three space-separated integers a, b, c denoting the edge between a and b with weight c.
Next line will contain Q (number of queries)
Next Q lines will contain two space-separated integers a and b.
Output Format:
For each query of each test case print the answer in a newline.
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= M <= 10^4
1 <= Q <= 10^4
1 <= wt <= 10^5 (for each edge)
Note: Graph may contain multiple edges.
Sample Input:
1
3 6
3 1 4
1 3 17
2 3 2
1 3 7
3 2 11
2 3 15
3
1 1 
2 2 
2 3 
Sample output:
0
0
2
*/


#include<bits/stdc++.h>
using namespace std;


void floydWarshall(int n, int m,vector<vector<int>> &d,vector<vector<int>> &edges)
{
	// Stores the shortest path between two vertices.
	
	// Add all edges to the matrix.
	for (int i = 0; i < m; i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
        if(d[u][v]>w && d[v][u]>w){
            d[u][v] = w;
            d[v][u]=w;
        }
		
        
	}

	// Apply Flloyd Warshall's Algorithm.
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][k] != 1e9 && d[k][j] != 1e9)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
	// Return dist between src and dest.
	//return d[src][dest];
    //return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> edges(m,vector<int>(3,0));
        for(int i=0;i<m;i++){
            int a,b,wt;
            cin>>a>>b>>wt;
            edges[i][0]=a;
            edges[i][1]=b;
            edges[i][2]=wt;
        }
        vector<vector<int>> d(n+1,vector<int>(n+1,0));

		// Initialize all the values to 1e9 except i, i which initializes to 0.
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					d[i][j] = 0;
				}
				else
				{
					d[i][j] = 1e9;
				}
		}
	}
        floydWarshall(n,m,d,edges);
        //cout<<floydWarshall(n,m,edges)<<endl;
        int q;
        cin>>q;
        while(q--){
            int src,dest;
            cin>>src>>dest;
            cout<<d[src][dest]<<endl;
        }
        
    }
}