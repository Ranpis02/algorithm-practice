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
    next = nullptr;
    random = nullptr;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    Node dummy(-1);
    Node *p = &dummy;
    Node *t = head;

    vector<Node *> origin;
    vector<Node *> deepCopy;

    unordered_map<Node *, int> randMap;
    int idx = 0;
    while (t)
    {
      origin.push_back(t);
      randMap.insert({t, idx});

      Node *node = new Node(t->val);
      deepCopy.push_back(node);
      t = t->next;
      idx++;
    }

    int n = origin.size();
    deepCopy.push_back(nullptr);
    randMap.insert({nullptr, n});

    unordered_map<int, int> idxMap;
    for (int i = 0; i < n; i++)
    {
      if (randMap.count(origin[i]->random))
        idxMap.insert({i, randMap[origin[i]->random]});
    }

    for (int i = 0; i < n; i++)
    {
      if (idxMap.count(i) && idxMap[i] <= n)
        deepCopy[i]->random = deepCopy[idxMap[i]];

      p->next = deepCopy[i];
      p = p->next;
    }

    return dummy.next;
  }
};

int main()
{

  return 0;
}