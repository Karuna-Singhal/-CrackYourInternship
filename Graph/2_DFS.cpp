#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, vector<int> &visited, vector<int> &ans)
{
  visited[node] = 1;
  ans.push_back(node);

  for (auto nbr : adj[node])
  {
    if (visited[nbr] == 0)
      dfs(adj, nbr, visited, ans);
  }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
  vector<int> ans;
  vector<int> visited(V, 0);

  for (int i = 0; i < V; i++)
  {
    if (visited[i] == 0)
    {
      dfs(adj, i, visited, ans);
    }
  }

  return ans;
}

int main()
{
  int v = 5;
  vector<int> adj[] = {{1, 2, 3}, {}, {4}, {}, {}};

  vector<int> ans = dfsOfGraph(v, adj);

  for (auto x : ans)
    cout << x << " ";

  return 0;
}