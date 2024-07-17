#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (int m = i + 1; m < nums.size(); m++)
    {
      if (m > i + 1 && nums[m] == nums[m - 1])
        continue;

      int j = m + 1;
      int k = nums.size() - 1;

      while (j < k)
      {
        long long sum = 0;
        sum += nums[i];
        sum += nums[m];
        sum += nums[j];
        sum += nums[k];
        if (sum == (long long)target)
        {
          ans.push_back({nums[i], nums[m], nums[j], nums[k]});
          j++;
          k--;
          while (j < k && nums[j] == nums[j - 1])
            j++;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }

        else if (sum > (long long)target)
          k--;
        else
          j++;
      }
    }
  }

  return ans;
}

int main()
{
  vector<int> arr = {1, 0, -1, 0, -2, 2};

  vector<vector<int>> ans = fourSum(arr, 0);

  for (int i = 0; i < ans.size(); i++)
  {
    for (auto x : ans[i])
      cout << x << " ";
    cout << endl;
  }
}