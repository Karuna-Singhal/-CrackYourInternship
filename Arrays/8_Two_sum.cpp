#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  unordered_map<int, int> mp;

  for (int i = 0; i < nums.size(); i++)
  {
    int x = target - nums[i];
    if (mp.find(x) != mp.end())
      return {i, mp[x]};

    mp[nums[i]] = i;
  }

  return {-1, -1};
}

int main()
{
  vector<int> arr = {2, 7, 11, 15};

  vector<int> ans = twoSum(arr, 9);
  cout << ans[0] << " " << ans[1];

  return 0;
}