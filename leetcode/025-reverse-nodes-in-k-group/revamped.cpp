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
    if (!head || k == 1)
      return head;

    ListNode dummy = ListNode(0);
    dummy.next = head;

    ListNode *pre = &dummy;
    ListNode *end = head;

    while (end->next)
    {
      int i = 0;
      for (int i = 0; i < k && end != nullptr; i++)
      {
        end = end->next;
      }

      if (end == nullptr)
        break;

      ListNode *start = pre->next;
      ListNode *next = end->next;

      end->next = nullptr;

      pre->next = reverse(start, end);
      start->next = next;

      pre = start;
      end = pre;
    }

    return dummy.next;
  }

  ListNode *reverse(ListNode *start, ListNode *end)
  {
    ListNode *pre = nullptr;
    ListNode *p = start;

    while (p)
    {
      ListNode *next = p->next;
      p->next = pre;

      pre = p;
      p = next;
    }

    return end;
  }
};

int main()
{

  return 0;
}