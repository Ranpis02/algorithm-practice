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

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode dummy(0);
    dummy.next = head;

    ListNode *p = head;
    ListNode *pre = &dummy;

    while (p)
    {
      if (p->next && p->val == p->next->val)
      {
        int val = p->val;

        while (p && p->val == val)
        {
          ListNode *tmp = p;
          p = p->next;
          delete tmp;
        }

        pre->next = p;
      }
      else
      {
        pre = p;
        p = p->next;
      }
    }

    return dummy.next;
  }
};

int main()
{

  return 0;
}