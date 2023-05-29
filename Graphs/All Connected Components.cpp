/*Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 1 to V.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
For each test case and each connected components print the connected components in sorted order in new line.
Order of connected components doesn't matter (print as you wish).
Constraints :
2 <= V <= 10000
1 <= E <= 10000
Sample Input 1:
1
4 2
2 1
4 3
Sample Output 1:
1 2
4 3



*/

#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj, int index, bool visited[], vector<int> &compo)
{
    compo.push_back(index);
    visited[index] = true;
    for (auto v : adj[index])
    {
        if (visited[v] == false)
        {
            dfs(adj, v, visited, compo);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool visited[n + 1];
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                vector<int> compo;
                dfs(adj, i, visited, compo);
                sort(compo.begin(), compo.end());
                for (int j = 0; j < compo.size(); j++)
                {
                    cout << compo[j] << " ";
                }
                cout << endl;
            }
        }
    }
}