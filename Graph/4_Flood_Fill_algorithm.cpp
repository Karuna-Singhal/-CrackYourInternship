#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
  int oldColor = image[sr][sc];
  if (oldColor == color)
    return image;
  int n = image.size();
  int m = image[0].size();

  int deltaR[4] = {-1, 0, 1, 0};
  int deltaC[4] = {0, 1, 0, -1};

  queue<pair<int, int>> q;
  q.push({sr, sc});
  image[sr][sc] = color;

  while (!q.empty())
  {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int newR = r + deltaR[i];
      int newC = c + deltaC[i];

      if (newR >= 0 && newC >= 0 && newR < n && newC < m && image[newR][newC] == oldColor)
      {
        image[newR][newC] = color;
        q.push({newR, newC});
      }
    }
  }
  return image;
}

int main()
{
  vector<vector<int>> image = {{1, 1, 1},
                               {1, 1, 0},
                               {1, 0, 1}};
  vector<vector<int>> ans = floodFill(image, 1, 1, 2);

  for (int i = 0; i < ans.size(); i++)
  {
    for (auto x : ans[i])
      cout << x << " ";

    cout << endl;
  }
}