/*

We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.
Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).
Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line will contain two space-separated integers N and M denoting the number of vertex and edges respectively.
Next M line will contain two space separated integers a, b denoting an edge from a to b.
Output Format:
For each test case output the bottom of the specified graph on a single line. 
Constraints:
1 <= T <= 50
1 <= N, M <= 10^5
Sample Input:
1
3 6
3 1
2 3
3 2
1 2
1 3
2 1
Sample Output:
1 2 3 

*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

void dfs2(int start, vector<int>* edgest, int* visited, unordered_set<int>* component){
	visited[start] = 1;
	component->insert(start);

	for (int i = 0; i < edgest[start].size(); ++i)
	{
		if (visited[edgest[start].at(i)]==0)
		{
			dfs2(edgest[start].at(i), edgest, visited, component);
		}
	}

	return;
}

void dfs(vector<int>* edges, int start, int* visited, stack<int> &s){
	visited[start] = 1;
	for (int i = 0; i < edges[start].size(); ++i)
	{
		if (visited[edges[start].at(i)] == 0)
		{
			dfs(edges, edges[start].at(i), visited, s);
		}
	}

	s.push(start);

	return;
}

unordered_set<unordered_set<int>*>* kosaraju(vector<int>* edges, vector<int>* edgest, int v){
	
	//Initialize an empty set of sets for the answer
	unordered_set<unordered_set<int>*>* ans = new unordered_set<unordered_set<int>*>();

	stack<int> s;
	int* visited = new int[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < v; ++i)
	{
		if (visited[i] == 0)
		{
			dfs(edges, i, visited, s);
		}

	}


	for (int i = 0; i < v; ++i)
	{
		visited[i] = 0;
	}

	// while(!s.empty()){
	// 	cout << s.top() << '\n';
	// 	s.pop();
	// }

	//return ans;
	while(!s.empty()){
		int t = s.top();
		s.pop();
		

		if (visited[t] == 0)
		{
			
			unordered_set<int>* component = new unordered_set<int>();
			dfs2(t, edgest, visited, component);
			ans->insert(component);
		}else{
			continue;
		}
	}

	return ans;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;
    int te;
    cin>>te;
    
	while(te--){

		int v, e;
		cin>>v;
		if (v==0)
		{
			break;
		}
		cin>>e;
		vector<int>* edges = new vector<int>[v];
		vector<int>* edgest = new vector<int>[v];

		for (int i = 0; i < e; ++i)
		{
			int a, b;
			cin>>a>>b;

			edges[a-1].push_back(b-1);
			edgest[b-1].push_back(a-1);
		}

		unordered_set<unordered_set<int>*>* components = kosaraju(edges, edgest, v);
		// auto itt = components->begin();
		// while(itt!=components->end()){
		// 	auto itt2 = (*itt)->begin();
		// 	while(itt2!=(*itt)->end()){
		// 		cout << *itt2+1 << ' ';
		// 		itt2++;
		// 	}
		// 	itt++;
		// 	cout << '\n';
		// }
		
	//	cout << (*components).size() << '\n';		

		auto it = components->begin();
		vector<int> ans;
		while(it!=components->end())
		{	
			int flag = 0;
			auto it2 = (*it)->begin();
			while(it2!=(*it)->end())
			{		
				//int i = 0;
				for (int i = 0; i < edges[*it2].size(); ++i)
				{

					if ((*it)->count(edges[*it2].at(i)) == 0)
					{
						flag = 1;
						break;

					}
				}
				if (flag == 1)
				{
					break;
				}
				it2++;
			}
			if (flag == 0)
			{
				//vector<int> ans;
				it2 = (*it)->begin();
				while(it2!=(*it)->end())
				{
					ans.push_back(*it2 + 1);
					//cout << *it2 + 1<< ' ';
					it2++;
				}
				
				//cout <<'\n';
				//break;
			}
			
			it++;
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans.at(i)<<" ";
		}
        cout<<endl;
	}

	

	return 0 ; 



}