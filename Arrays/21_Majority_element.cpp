#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
  int cnt = 0;
  int el = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    if (cnt == 0)
    {
      el = nums[i];
      cnt = 1;
    }
    else if (el == nums[i])
      cnt++;
    else
      cnt--;
  }

  return el;
}

int main()
{
  vector<int> arr = {1, 2, 2};
  cout << majorityElement(arr);
  return 0;
}