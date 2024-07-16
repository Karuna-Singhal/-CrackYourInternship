#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{

  sort(a.begin(), a.end());
  long long s = 0;
  long long e = m - 1;

  long long mini = INT_MAX;

  while (e < n)
  {
    mini = min(mini, a[e] - a[s]);

    s++;
    e++;
  }

  return mini;
}

int main()
{
  vector<long long> arr = {7, 3, 2, 4, 9, 12, 56};

  cout << findMinDiff(arr, 7, 3);

  return 0;
}