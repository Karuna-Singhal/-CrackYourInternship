#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int j = 0;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] != nums[j])
    {
      nums[j + 1] = nums[i];
      j++;
    }
  }
  return j + 1;
}

int main()
{
  vector<int> nums = {1, 1, 2};

  cout << removeDuplicates(nums);

  return 0;
}