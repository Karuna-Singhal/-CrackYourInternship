#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
  int s = 0;
  int e = height.size() - 1;
  int total = 0;
  while (s < e)
  {
    int sum = (e - s) * min(height[s], height[e]);
    total = max(total, sum);

    if (height[s] < height[e])
      s++;
    else
      e--;
  }

  return total;
}

int main()
{
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << maxArea(height);

  return 0;
}