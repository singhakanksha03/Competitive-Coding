/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in new line.
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

int find_path_bfs(int **aj,int v,int start,int end,map<int,int> &m){
    queue<int> q;
    int visited[v+1]{};
    // stores the child->parent relation for each node
    // map<int,int> m;
    
    q.push(start);
    visited[start]=1;
    m[start]=-1;

    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(i==current){
                continue;
            }
            if(aj[current][i]==1){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                    m[i]=current;
                }
                if(i==end){
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

    while(e--){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;


    map<int,int> path;
    int ans=find_path_bfs(aj,v,v1,v2,path);
    if(ans==1){
        // print path
        int current=v2;
        while(current!=-1){
            cout<<current<<" ";
            current=path[current];
        }
    }
        cout<<endl;
    }
    // delete memory
    return 0;
}