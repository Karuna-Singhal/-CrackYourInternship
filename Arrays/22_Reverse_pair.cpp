#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &nums, int s, int mid, int e)
{
  vector<int> temp;
  int i = s;
  int j = mid + 1;

  while (i <= mid && j <= e)
  {
    if (nums[i] > nums[j])
    {
      temp.push_back(nums[j]);
      j++;
    }
    else
    {
      temp.push_back(nums[i]);
      i++;
    }
  }

  while (i <= mid)
  {
    temp.push_back(nums[i]);
    i++;
  }
  while (j <= e)
  {
    temp.push_back(nums[j]);
    j++;
  }

  for (int i = s; i <= e; i++)
  {
    nums[i] = temp[i - s];
  }
}

long long countReversePair(vector<int> &nums, long long s, long long mid, long long e)
{
  int count = 0;
  int j = mid + 1;
  for (int i = s; i <= mid; i++)
  {
    while (j <= e && nums[i] > 2LL * nums[j])
    {
      j++;
    }
    count += (j - mid - 1);
  }
  return count;
}

long long merge(vector<int> &nums, long long s, long long e)
{
  long long cnt = 0;
  if (s >= e)
    return cnt;
  long long mid = (s + e) / 2;
  cnt += merge(nums, s, mid);
  cnt += merge(nums, mid + 1, e);
  cnt += countReversePair(nums, s, mid, e);
  mergeSort(nums, s, mid, e);
  return cnt;
}
int reversePairs(vector<int> &nums)
{
  long long e = nums.size() - 1;
  return merge(nums, 0, e);
}

int main()
{
  vector<int> arr = {1, 3, 2, 3, 1};
  cout << reversePairs(arr);

  return 0;
}