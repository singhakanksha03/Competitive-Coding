/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
First line will contain T(number of test case), each test follow as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in newline.
Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int find_path_dfs(int **aj,int v,int *visited,int start,int end,queue<int> *path){
    visited[start]=1;

    // if end reached
    if(start==end){
        path->push(end);
        return 1;
    }
    // check all nodes connected to current node
    for(int i=0;i<v;i++){
        if(i==start){
            continue;
        }
        if(aj[start][i]==1){
            if(visited[i]==0){
                int ans=find_path_dfs(aj,v,visited,i,end,path);
                // if my child has found a possible path
                // add current to path and notify my parent
                if(ans==1){
                    path->push(start);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int v,e;
    cin>>v>>e;
    int **aj=new int*[v];
    for(int i=0;i<v;i++){
        aj[i]=new int[v]{};
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;

    // in this queue the first possible path will be stored
    queue<int> *path=new queue<int>;

    int *visited=new int[v+1]{};
    int ans=find_path_dfs(aj,v,visited,v1,v2,path);
    // if path found, print
    if(ans==1){
        // print solution
        while(!path->empty()){
            int current=path->front();
            cout<<current<<" ";
            path->pop();
        }
    }
        cout<<endl;
    }
    return 0;
}