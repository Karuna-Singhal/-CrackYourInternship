#include <bits/stdc++.h>
using namespace std;

void pnc(vector<int> &arr, int s, int e, set<vector<int>> &st)
{
  if (s == e)
  {
    st.insert(arr);
  }
  else
  {
    for (int i = s; i <= e; i++)
    {
      swap(arr[s], arr[i]);
      pnc(arr, s + 1, e, st);
      swap(arr[s], arr[i]);
    }
  }
}

vector<vector<int>> uniquePerms(vector<int> &arr, int n)
{
  set<vector<int>> st;
  pnc(arr, 0, n - 1, st);

  vector<vector<int>> ans;
  for (auto x : st)
  {
    ans.push_back(x);
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 2, 1};
  vector<vector<int>> ans = uniquePerms(arr, 3);

  for (int i = 0; i < ans.size(); i++)
  {
    for (auto x : ans[i])
      cout << x << " ";
    cout << endl;
  }

  return 0;
}