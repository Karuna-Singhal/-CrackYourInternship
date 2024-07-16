#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, vector<vector<int>> &dp, int buy, int idx)
{
  if (idx == prices.size())
    return 0;

  if (dp[idx][buy] != -1)
    return dp[idx][buy];

  if (buy)
  {
    return dp[idx][buy] = max(-prices[idx] + solve(prices, dp, 0, idx + 1), solve(prices, dp, 1, idx + 1));
  }

  return dp[idx][buy] = max(prices[idx] + solve(prices, dp, 1, idx + 1), solve(prices, dp, 0, idx + 1));
}

int maxProfit(vector<int> &prices)
{
  int n = prices.size();
  vector<vector<int>> dp(n, vector<int>(2, -1));

  return solve(prices, dp, 1, 0);
}

int main()
{
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << maxProfit(prices);

  return 0;
}