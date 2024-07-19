#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
  int prev1 = 1;
  int prev2 = 1;
  int curr = 0;
  for (int i = 2; i <= n; i++)
  {
    curr = prev1 + prev2;
    prev1 = prev2;
    prev2 = curr;
  }

  return prev2;
}

int main()
{
  int n = 2;

  cout << climbStairs(n);

  return 0;
}