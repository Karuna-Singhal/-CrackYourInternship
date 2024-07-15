#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &arr)
{
  int s = 0;
  int e = arr.size() - 1;
  int mid = 0;

  while (mid <= e)
  {
    if (arr[mid] == 0)
    {
      swap(arr[mid], arr[s]);
      s++;
      mid++;
    }
    else if (arr[mid] == 1)
      mid++;

    else if (arr[mid] == 2)
    {
      swap(arr[mid], arr[e]);
      e--;
    }
  }
}

int main()
{
  vector<int> arr = {0, 1, 2, 0, 2, 1};
  sortColors(arr);
  for (auto x : arr)
    cout << x << " ";

  return 0;
}