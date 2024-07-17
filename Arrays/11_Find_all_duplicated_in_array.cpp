#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
  {
    int ind = abs(nums[i]) - 1;
    if (nums[ind] < 0)
      ans.push_back(abs(nums[i]));

    nums[ind] = -nums[ind];
  }
  return ans;
}

int main()
{
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> ans = findDuplicates(nums);

  for (auto x : ans)
    cout << x << " ";

  return 0;
}