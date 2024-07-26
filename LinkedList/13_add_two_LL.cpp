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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *dummy = new ListNode(-1);
  ListNode *temp = dummy;
  int carry = 0;

  while (l1 != NULL || l2 != NULL || carry != 0)
  {
    int sum = 0;
    if (l1 != NULL)
    {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2 != NULL)
    {
      sum += l2->val;
      l2 = l2->next;
    }
    sum += carry;
    carry = sum / 10;
    ListNode *newnode = new ListNode(sum % 10);
    temp->next = newnode;
    temp = temp->next;
  }
  return dummy->next;
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

  ListNode *ans = addTwoNumbers(head1, head);
  cout << ans->val;
}