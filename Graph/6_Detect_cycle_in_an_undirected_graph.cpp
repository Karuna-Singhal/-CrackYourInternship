//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  bool bfs(vector<int> adj[], int n, vector<int> &visited)
  {
    queue<pair<int, int>> q;

    q.push({n, -1});
    visited[n] = 1;

    while (!q.empty())
    {
      int node = q.front().first;
      int parent = q.front().second;
      q.pop();

      for (auto nbr : adj[node])
      {
        if (visited[nbr] == 0)
        {
          visited[nbr] = 1;
          q.push({nbr, node});
        }
        else if (parent != nbr)
          return true;
      }
    }
    return false;
  }
  // Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[])
  {

    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (visited[i] == 0)
      {
        if (bfs(adj, i, visited))
          return true;
      }
    }
    return false;
  }
};

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isCycle(V, adj);
    if (ans)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
// } Driver Code Ends