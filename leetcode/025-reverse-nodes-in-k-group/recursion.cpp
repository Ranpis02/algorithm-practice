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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (!head)
      return head;

    ListNode *p = head;

    for (int i = 0; i < k; i++)
    {
      if (p)
        p = p->next;
      else
        return head;
    }

    ListNode *pre = nullptr;
    ListNode *crr = head;

    for (int i = 0; i < k; i++)
    {
      ListNode *next = crr->next;

      crr->next = pre;
      pre = crr;
      crr = next;
    }

    head->next = reverseKGroup(crr, k);

    return pre;
  }
};

int main()
{

  return 0;
}