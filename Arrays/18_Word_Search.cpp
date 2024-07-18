#include <bits/stdc++.h>
using namespace std;

int deltaR[4] = {-1, 0, 1, 0};
int deltaC[4] = {0, 1, 0, -1};

bool dfs(vector<vector<char>> &board, string word, int idx, vector<vector<int>> &visited, int i, int j)
{
  if (idx == word.length())
    return true;
  if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx] || visited[i][j] != 0)
  {
    return false;
  }
  visited[i][j] = 1;

  for (int k = 0; k < 4; k++)
  {
    int r = i + deltaR[k];
    int c = j + deltaC[k];

    if (dfs(board, word, idx + 1, visited, r, c))
      return true;
  }
  visited[i][j] = 0;
  return false;
}

bool exist(vector<vector<char>> &board, string word)
{
  int n = board.size();
  int m = board[0].size();
  vector<vector<int>> visited(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == word[0])
      {
        if (dfs(board, word, 0, visited, i, j))
          return true;
      }
    }
  }
  return false;
}

int main()
{
  vector<vector<char>> arr = {{'A', 'B', 'C', 'E'},
                              {'S', 'F', 'C', 'S'},
                              {'A', 'D', 'E', 'E'}};
  string str = "ABCCED";

  cout << exist(arr, str);
  return 0;
}
