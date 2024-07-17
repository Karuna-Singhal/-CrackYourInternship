#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
  unordered_map<int, int> mp;
  int sum = 0;
  int count = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
    if (sum % k == 0)
      count++;

    int mod = sum % k;
    if (mod < 0)
      mod += k;
    if (mp.find(mod) != mp.end())
    {
      count += mp[mod];
    }
    mp[mod]++;
  }
  return count;
}

int main()
{
  vector<int> nums = {4, 5, 0, -2, -3, 1};
  cout << subarraysDivByK(nums, 5);

  return 0;
}