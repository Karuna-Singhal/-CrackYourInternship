
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

struct Node *start = NULL;

class Solution
{
public:
  Node *segregate(Node *head)
  {

    if (head == NULL)
      return NULL;

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroTemp = zeroHead;
    Node *oneTemp = oneHead;
    Node *twoTemp = twoHead;
    Node *temp = head;

    while (temp != NULL)
    {
      if (temp->data == 0)
      {
        zeroTemp->next = temp;
        temp = temp->next;
        zeroTemp = zeroTemp->next;
      }
      else if (temp->data == 1)
      {
        oneTemp->next = temp;
        temp = temp->next;
        oneTemp = oneTemp->next;
      }
      else
      {
        twoTemp->next = temp;
        temp = temp->next;
        twoTemp = twoTemp->next;
      }
    }

    zeroTemp->next = oneHead->next ? oneHead->next : twoHead->next;
    oneTemp->next = twoHead->next;
    twoTemp->next = NULL;

    return zeroHead->next;
  }
};

void printList(struct Node *Node)
{
  while (Node != NULL)
  {
    printf("%d ", Node->data);
    Node = Node->next;
  }
  printf("\n");
}

void insert(int n1)
{
  int n, value, i;

  n = n1;
  struct Node *temp;
  for (i = 0; i < n; i++)
  {
    scanf("%d", &value);

    if (i == 0)
    {
      start = new Node(value);
      temp = start;
      continue;
    }
    else
    {
      temp->next = new Node(value);
      temp = temp->next;
      temp->next = NULL;
    }
  }
}

int main()
{

  int n;

  int t;
  scanf("%d", &t);

  while (t--)
  {
    scanf("%d", &n);

    insert(n);
    Solution ob;
    struct Node *newHead = ob.segregate(start);
    printList(newHead);
  }

  return 0;
}
