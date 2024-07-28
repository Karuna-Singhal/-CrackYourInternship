class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int sr = 0;
    int sc = 0;
    int er = n - 1;
    int ec = m - 1;

    while (sr <= er && sc <= ec)
    {
      for (int i = sc; i <= ec; i++)
      {
        ans.push_back(matrix[sr][i]);
      }

      for (int i = sr + 1; i <= er; i++)
      {
        ans.push_back(matrix[i][ec]);
      }

      for (int i = ec - 1; i >= sc; i--)
      {
        if (sr == er)
          break;
        ans.push_back(matrix[er][i]);
      }
      for (int i = er - 1; i >= sr + 1; i--)
      {
        if (sc == ec)
          break;
        ans.push_back(matrix[i][sc]);
      }
      sr++;
      sc++;
      er--;
      ec--;
    }
    return ans;
  }
};