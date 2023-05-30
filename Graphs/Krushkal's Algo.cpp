/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the total weight of Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
class Edge{
    public:
    int v1,v2,w;
};

bool compare(Edge e1,Edge e2){
    return e1.w<e2.w;
}

// go to the top most parent and return it
int get_parent(int current_vertex, int *parents){
	if (current_vertex == parents[current_vertex]){
		return current_vertex;
	}
	return get_parent(parents[current_vertex], parents);
}

// go to the topmost parent of 1st vertex and set its parent as second vertex
void set_parent(int v1, int *parents,int v2){
	if (v1 == parents[v1]){
		parents[v1]=v2;
        return;
	}
	return set_parent(parents[v1], parents,v2);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int v,e,count=0;
        cin>>v>>e;
        int *parent=new int[v];
        //vector<Edge> output;
        int sum=0;
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
        Edge *A=new Edge[e];
        for(int i=0;i<e;i++){
            cin>>A[i].v1>>A[i].v2>>A[i].w;
        }
        sort(A,A+e,compare);
        
        for(int i=0;i<e;i++){
            if(count>=v-1){
                break;
            }
            if(get_parent(A[i].v1,parent)!=get_parent(A[i].v2,parent)){
                set_parent(A[i].v1,parent,A[i].v2);
                sum+=A[i].w;
                count++; 
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}


