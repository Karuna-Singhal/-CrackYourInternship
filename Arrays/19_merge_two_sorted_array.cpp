#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int i = m - 1;
  ;
  int j = n - 1;
  int k = m + n - 1;

  while (i >= 0 && j >= 0)
  {
    if (nums1[i] >= nums2[j])
    {
      nums1[k] = nums1[i];
      k--;
      i--;
    }
    else
    {
      nums1[k] = nums2[j];
      k--;
      j--;
    }
  }
  while (i >= 0)
  {
    nums1[k] = nums1[i];
    k--;
    i--;
  }
  while (j >= 0)
  {
    nums1[k] = nums2[j];
    k--;
    j--;
  }
}

int main()
{
  vector<int> arr1 = {1, 2, 3, 0, 0, 0};
  vector<int> arr2 = {3, 4, 5};
  merge(arr1, 3, arr2, 3);

  for (auto x : arr1)
    cout << x << " ";

  return 0;
}