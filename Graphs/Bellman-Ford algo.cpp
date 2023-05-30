/*
you are given a weighted directed graph G with n vertices and m edges, and two specified vertex src and des. You want to find the length of shortest paths from vertex src to des. The graph may contain the edges with negative weight.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line1: contain two space-separated integers N and M denoting the number of vertex and number of edges in graph respectively.
Line2: contain two space-separated integers src, des.
Next M line will contain three space-separated integers a, b, wt representing the edge from a to b with weight wt.
Output Format:
For each test case print the distance of des from src in new line.
Note: In case of no path is found print (10 ^ 9) in that case.
Constraints:
1 <= T <= 100
1 <= N <= 200
1 <= M <= min(800, N*(N-1))
1 <= a,b <= N
-10^5 <= wt <= 10^5
Sample Input:
1
3 6
3 1
3 1 -2
1 3 244
2 3 -2
2 1 201
3 2 220
1 2 223
Sample output:
-2
*/


#include <bits/stdc++.h>
using namespace std;


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    // Create a vector to store the distances from source.
    vector<int> d(n + 1, 1e9);
    // Distance of source to source is 0.
    d[src] = 0;

    // Apply bellmonford algorithm.
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (d[u] != 1e9 && d[v] > (d[u] + w)) {
                d[v] = d[u] + w;
            }
        }
    }

    // Return the distance of destination.
    return d[dest];
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int src,dest;
        cin>>src>>dest;
        vector<vector<int>> edges(m,vector<int>(3,0));
        for(int i=0;i<m;i++){
            int a,b,wt;
            cin>>a>>b>>wt;
            edges[i][0]=a;
            edges[i][1]=b;
            edges[i][2]=wt;
        }
        cout<<bellmonFord(n,m,src,dest,edges)<<endl;
    }
}