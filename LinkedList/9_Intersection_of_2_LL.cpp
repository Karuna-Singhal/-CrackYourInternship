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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
  if (headA == NULL || headB == NULL)
    return NULL;

  ListNode *temp1 = headA;
  ListNode *temp2 = headB;

  while (temp1 != temp2)
  {
    temp1 = temp1->next;
    temp2 = temp2->next;
    if (temp1 == NULL && temp2 != NULL)
      temp1 = headB;
    if (temp2 == NULL && temp1 != NULL)
      temp2 = headA;
    if (temp1 == temp2)
      return temp1;
  }

  return temp1;
}

int main()
{
  ListNode *head = new ListNode(6);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  ListNode *head1 = new ListNode(7);
  head1->next = new ListNode(3);
  head1->next->next = new ListNode(4);

  ListNode *ans = getIntersectionNode(head1, head);
  cout << ans->val;
}