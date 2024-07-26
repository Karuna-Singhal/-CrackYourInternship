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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
  if (head == NULL)
    return head;

  ListNode *fast = head;
  for (int i = 0; i < n; i++)
  {
    fast = fast->next;
  }

  ListNode *slow = head;
  if (fast == NULL)
    return head->next;
  while (fast->next != NULL)
  {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return head;
}

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  ListNode *ans = removeNthFromEnd(head, 4);
  cout << ans->val;
}