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

ListNode *middle(ListNode *head)
{
  if (head == NULL)
    return NULL;

  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode *merge(ListNode *left, ListNode *right)
{
  ListNode *dummy = new ListNode(-1);
  ListNode *temp = dummy;
  while (left != NULL && right != NULL)
  {
    if (left->val > right->val)
    {
      temp->next = right;
      right = right->next;
    }
    else
    {
      temp->next = left;
      left = left->next;
    }
    temp = temp->next;
  }
  if (left)
    temp->next = left;
  if (right)
    temp->next = right;

  return dummy->next;
}

ListNode *sortList(ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  ListNode *mid = middle(head);
  ListNode *right = mid->next;
  mid->next = NULL;
  ListNode *left = head;

  left = sortList(left);
  right = sortList(right);

  return merge(left, right);
}

int main()
{
  ListNode *head = new ListNode(6);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  ListNode *ans = sortList(head);
  cout << ans->val;
}