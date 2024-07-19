#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
  vector<int> ans;
  queue<int> q;
  vector<int> visited(V, 0);
  q.push(0);
  visited[0] = 1;

  while (!q.empty())
  {
    int a = q.front();
    q.pop();

    ans.push_back(a);
    for (auto nbr : adj[a])
    {
      if (visited[nbr] == 0)
      {
        visited[nbr] = 1;
        q.push(nbr);
      }
    }
  }
  return ans;
}

int main()
{
  int v = 5;
  vector<int> adj[] = {{1, 2, 3}, {}, {4}, {}, {}};

  vector<int> ans = bfsOfGraph(v, adj);

  for (auto x : ans)
    cout << x << " ";

  return 0;
}