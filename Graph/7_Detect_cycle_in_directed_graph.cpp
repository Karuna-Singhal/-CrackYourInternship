//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[])
  {
    vector<int> indegree(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < adj[i].size(); j++)
      {
        indegree[adj[i][j]]++;
      }
    }

    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }
    int cnt = 0;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      cnt++;

      for (auto nbr : adj[node])
      {
        indegree[nbr]--;
        if (indegree[nbr] == 0)
          q.push(nbr);
      }
    }

    if (cnt == V)
      return false;
    return true;
  }
};

//{ Driver Code Starts.

int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    Solution obj;
    cout << obj.isCyclic(V, adj) << "\n";
  }

  return 0;
}

// } Driver Code Ends