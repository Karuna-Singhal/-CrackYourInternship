#include <bits/stdc++.h>
using namespace std;

int ceilVal(vector<int> &arr, int x)
{
  int s = 0;
  int e = arr.size() - 1;
  int ans = -1;
  while (s <= e)
  {
    int mid = (s + e) / 2;
    if (arr[mid] >= x)
    {
      ans = arr[mid];
      e--;
    }
    else
      s++;
  }
  return ans;
}

int main()
{
  vector<int> arr = {1, 2, 8, 10, 10, 12, 19};

  cout << ceilVal(arr, 3);

  return 0;
}