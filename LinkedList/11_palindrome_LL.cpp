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

ListNode *reverseList(ListNode *head)
{
  ListNode *prev = NULL;
  ListNode *forward = NULL;
  ListNode *curr = head;

  while (curr != NULL)
  {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  return prev;
}

bool isPalindrome(ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return true;

  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next != NULL && fast->next->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode *tempHead = reverseList(slow->next);
  ListNode *firstHead = head;
  ListNode *secondHead = tempHead;

  while (secondHead != NULL)
  {
    if (firstHead->val != secondHead->val)
    {
      reverseList(tempHead);
      return false;
    }
    firstHead = firstHead->next;
    secondHead = secondHead->next;
  }
  reverseList(tempHead);
  return true;
}

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(1);

  bool ans = isPalindrome(head);
  cout << ans;
}