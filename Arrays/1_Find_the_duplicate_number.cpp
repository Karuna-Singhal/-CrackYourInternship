#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
  for (int i = 0; i < nums.size(); i++)
  {
    int ind = abs(nums[i]);
    if (nums[ind] < 0)
      return ind;
    nums[ind] = nums[ind] * (-1);
  }
  return -1;
}

int main()
{
  vector<int> arr = {1, 3, 4, 2, 2};

  cout << findDuplicate(arr);

  return 0;
}