#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int> &prices)
{
  int n = prices.size();
  vector<int> prev(2 * k + 1, 0);
  vector<int> curr(2 * k + 1, 0);

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 2 * k - 1; j >= 0; j--)
    {
      if (j % 2 == 0)
        curr[j] = max(-prices[i] + prev[j + 1], curr[j]);
      else
        curr[j] = max(prices[i] + prev[j + 1], curr[j]);
    }
    prev = curr;
  }

  return prev[0];
}

int main()
{
  vector<int> arr = {2, 4, 1};
  cout << maxProfit(2, arr);
}