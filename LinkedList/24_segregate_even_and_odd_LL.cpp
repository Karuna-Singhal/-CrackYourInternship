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

ListNode *oddEvenList(ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  ListNode *oddHead = head;
  ListNode *evenHead = head->next;
  ListNode *oddTemp = oddHead;
  ListNode *evenTemp = evenHead;

  while (evenTemp != NULL && evenTemp->next != NULL)
  {
    oddTemp->next = evenTemp->next;
    oddTemp = oddTemp->next;

    evenTemp->next = oddTemp->next;
    evenTemp = evenTemp->next;
  }

  if (oddTemp == NULL)
    return evenHead;

  oddTemp->next = evenHead;
  return oddHead;
}

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  ListNode *ans = oddEvenList(head);
  cout << ans->val;
}