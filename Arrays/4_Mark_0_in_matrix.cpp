#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
  int col0 = 1;
  int n = matrix.size();
  int m = matrix[0].size();

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == 0 && j == 0)
      {
        matrix[i][0] = 0;
        col0 = 0;
      }
      else if (matrix[i][j] == 0 && j != 0)
      {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (int i = n - 1; i > 0; i--)
  {
    for (int j = m - 1; j > 0; j--)
    {
      if (matrix[0][j] == 0 || matrix[i][0] == 0)
        matrix[i][j] = 0;
    }
  }

  for (int j = 0; j < m; j++)
  {
    if (matrix[0][0] == 0)
      matrix[0][j] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    if (col0 == 0)
      matrix[i][0] = 0;
  }
}

int main()
{
  vector<vector<int>> matrix = {{1, 1, 1},
                                {1, 0, 1},
                                {1, 1, 1}};
  setZeroes(matrix);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}