/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?
Input Format:
The first line of input will contain T(number of test cases), each test case follows as.
Line 1: Two Integers N and M (separated by space)
Next 'M' lines, each have two space-separated integers, 'u' and 'v', denoting that there exists an edge between Vertex 'u' and Vertex 'v'.
Output Format:
Print number of Islands for each test case in new line.
Constraints:
1 <= T <= 10
1 <= N <= 1000
1 <= M <= min((N*(N-1))/2, 1000)
0 <= u[i] ,v[i] < N
Output Return Format :
The count the number of connected groups of islands
Sample Input :
1
2 1
0 1
Sample Output :
1 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs_traversal(int **aj,int v,int *visited,int start){
    visited[start]=1;
    for(int i=0;i<v;i++){
        if(aj[start][i]==1){
            if(visited[i]==0){
                dfs_traversal(aj,v,visited,i);
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        
    
    int v,e;
    cin>>v>>e;
    int **aj=new int*[v];
    for(int i=0;i<v;i++){
        aj[i]=new int[v];
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        aj[a][b]=1;
        aj[b][a]=1;
    }
    int *visited=new int[v]{};
    int count=0;
    // counting number of groups
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            dfs_traversal(aj,v,visited,i);
            count++;
        }
    }
    cout<<count<<"\n";
    }
    return 0;
}