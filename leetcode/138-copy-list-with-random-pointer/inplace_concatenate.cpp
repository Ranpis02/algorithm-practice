#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return nullptr;

    Node *p = head;

    while (p)
    {
      Node *newNode = new Node(p->val);

      newNode->next = p->next;
      p->next = newNode;
      p = newNode->next;
    }

    p = head;

    // Correct the random pointer
    while (p)
    {
      p->next->random = p->random ? p->random->next : nullptr;
      p = p->next->next;
    }

    p = head;
    Node *newHead = head->next;
    Node *copy = newHead;
    // Split the linked list
    while (p)
    {
      p->next = p->next->next;
      copy->next = copy->next ? copy->next->next : nullptr;

      p = p->next;
      copy = copy->next;
    }

    return newHead;
  }
};

int main()
{

  return 0;
}