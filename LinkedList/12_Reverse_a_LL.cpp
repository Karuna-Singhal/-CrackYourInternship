#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head, ListNode *&prev, ListNode *&forward)
{
  if (head == NULL)
    return prev;
  ListNode *temp = head;

  forward = temp->next;
  temp->next = prev;
  prev = temp;
  temp = reverseList(forward, prev, forward);

  return prev;
}

int main()
{
  ListNode *prev = NULL;
  ListNode *forward = NULL;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *ans = reverseList(head, prev, forward);
  cout << ans->val;
}