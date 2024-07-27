class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<int> indegree(numCourses, 0);
    vector<int> adj[numCourses];
    queue<int> q;

    for (int i = 0; i < prerequisites.size(); i++)
    {
      int u = prerequisites[i][0];
      int v = prerequisites[i][1];
      adj[v].push_back(u);
      indegree[u]++;
    }

    for (int i = 0; i < numCourses; i++)
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

    if (cnt == numCourses)
      return true;
    return false;
  }
};