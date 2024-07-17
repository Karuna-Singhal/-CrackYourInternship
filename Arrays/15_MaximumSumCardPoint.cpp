#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k)
{
  int n = cardPoints.size();
  int total = 0;
  int maxSum = 0;
  for (int i = 0; i < k; i++)
    total += cardPoints[i];

  maxSum = total;
  int j = n - 1;
  for (int i = k - 1; i >= 0; i--)
  {
    total += cardPoints[j] - cardPoints[i];
    maxSum = max(maxSum, total);
    j--;
  }
  return maxSum;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 1};
  cout << maxScore(nums, 3);

  return 0;
}