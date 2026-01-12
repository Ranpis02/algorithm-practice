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

    unordered_map<Node *, Node *> mp;

    Node *p = head;

    while (p)
    {
      mp[p] = new Node(p->val);
      p = p->next;
    }

    p = head;

    while (p)
    {
      // mp[p]->random = mp[p->random];
      // mp[p]->next = mp[p->next];
      mp[p]->next = p->next ? mp[p->next] : nullptr;
      mp[p]->random = p->random ? mp[p->random] : nullptr;

      p = p->next;
    }

    return mp[head];
  }
};

int main()
{

  return 0;
}