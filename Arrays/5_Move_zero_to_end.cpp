#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
  int firstzero = -1;
  int n = nums.size();

  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
    {
      firstzero = i;
      break;
    }
  }

  if (firstzero == -1)
    return;

  for (int i = firstzero + 1; i < n; i++)
  {
    if (nums[i] != 0)
    {
      swap(nums[i], nums[firstzero]);
      firstzero++;
    }
  }
}

int main()
{
  vector<int> arr = {0, 1, 0, 3, 12};
  moveZeroes(arr);
  for (auto x : arr)
    cout << x << " ";

  return 0;
}