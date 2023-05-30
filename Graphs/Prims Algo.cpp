/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Prim's algorithm.
Input Format :
First line will contain T(number of test case), each test case follows as. 
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Weight of MST for each test case in new line.
Constraints :
1 <= T <= 10
2 <= V, E <= 10^5
1 <= wt <= 10^4
Sample Input 1 :
1
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
9
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// here we'll find the vertex which is not visited and which has the min weight
int getminvertex(bool *visited,int *weight,int v){
    int minvertex=-1;
    for(int i=0;i<v;i++){
        // if not visited 
        if(visited[i]==0&&((minvertex==-1)||(weight[minvertex]>weight[i]))){
            minvertex=i;
        }
    }
    return minvertex;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        
    
    int v,e,sum=0;
    cin>>v>>e;
    int **aj=new int*[v];
    for(int i=0;i<v;i++){
        aj[i]=new int[v]{};
        for(int j=0;j<v;j++){
            aj[i][j]=INT_MAX;
        }
    }
    
    for(int i=0;i<e;i++){
        int ei,ej,wt;
        cin>>ei>>ej>>wt;
        if(aj[ei][ej]<wt){
            continue;
        }else{
        aj[ei][ej]=wt;
        aj[ej][ei]=wt;
        }
    }
	// for(int i=0;i<v;i++){
	// for(int j=0;j<v;j++){
	// cout<<aj[i][j]<<" ";
	// }
	// cout<<endl;
	// }
    // make required arrays
    bool *visited=new bool[v]{};
    int *parent=new int[v];
    int *weight=new int[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
        parent[i]=-1;
    }

    // select any vertex as starting vertex
    // as we have to include every vertex in the MST, we can choose any one
    parent[0]=-1;
    weight[0]=0;

    for(int i=0;i<v-1;i++){
        // get min vertex - unvisited vertex with minimum weight
        int minvertex=getminvertex(visited,weight,v);
        visited[minvertex]=1;

        // explore all the possible neighbours from this vertex and update parent and new weights of these vertices
        for(int j=0;j<v;j++){
            // checking if there is some vertex connected to min vertex
            // proceed only if its not visited
            if(aj[minvertex][j]!=0&&visited[j]==0){
                // update weight if the new weight is better than previous
                if(weight[j]>aj[minvertex][j]){
                    weight[j]=aj[minvertex][j];
                    parent[j]=minvertex;
                }
            }
        }
    }

    // printing the mst
    for(int i=1;i<v;i++){
        // if(parent[i]<i){
        //     cout<<parent[i]<<" "<<i<<" "<<weight[i]<<"\n";
        // }else{
        //     cout<<i<<" "<<parent[i]<<" "<<weight[i]<<"\n";
        // }
        sum+=weight[i];
    }
    cout<<sum<<endl;
    delete parent;
    delete visited;
    delete weight;
    }
    return 0;
}