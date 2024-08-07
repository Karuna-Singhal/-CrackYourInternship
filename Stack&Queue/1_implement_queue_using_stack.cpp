#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
  stack<int> s1;
  stack<int> s2;

public:
  MyQueue()
  {
  }

  void push(int x)
  {
    if (!s1.empty())
    {
      while (!s1.empty())
      {
        int a = s1.top();
        s1.pop();
        s2.push(a);
      }
    }
    s1.push(x);
    while (!s2.empty())
    {
      int a = s2.top();
      s2.pop();
      s1.push(a);
    }
  }

  int pop()
  {
    if (s1.empty())
    {
      return -1;
    }
    int a = s1.top();
    s1.pop();
    return a;
  }

  int peek()
  {
    return s1.top();
  }

  bool empty()
  {
    if (s1.empty())
    {
      return true;
    }
    return false;
  }
};
