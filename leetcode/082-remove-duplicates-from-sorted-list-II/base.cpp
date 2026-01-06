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

ListNode *create(vector<int> &nums)
{
  ListNode dummy(0);
  ListNode *p = &dummy;

  for (int num : nums)
  {
    p->next = new ListNode(num);
    p = p->next;
  }

  return dummy.next;
}

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode dummy(-101);
    dummy.next = head;
    int dup = -101;

    ListNode *p = head, *pre = &dummy;

    while (p)
    {
      ListNode *next = p->next;

      if (next && p->val != next->val)
        pre = p;

      if (next && p->val == next->val)
        dup = p->val;

      if (p->val == dup)
      {
        while (p && p->val == dup)
        {
          next = p->next;
          pre->next = next;
          delete p;

          p = next;
        }
      }
      else
        p = next;
    }

    return dummy.next;
  }
};

int main()
{
  vector<int> nums = {1, 1};

  ListNode *head = create(nums);

  Solution *sol = new Solution;
  sol->deleteDuplicates(head);

  return 0;
}