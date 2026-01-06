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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    if (!head || left == right)
    {
      return head;
    }

    ListNode dummy(0);
    dummy.next = head;

    ListNode *pre = &dummy;

    for (int i = 0; i < left - 1; i++)
    {
      pre = pre->next;
    }

    ListNode *crr = pre->next;

    for (int i = 0; i < right - left; i++)
    {
      ListNode *next = crr->next;

      crr->next = next->next;
      next->next = pre->next;
      pre->next = next;
    }

    return dummy.next;
  }
};

int main()
{

  return 0;
}