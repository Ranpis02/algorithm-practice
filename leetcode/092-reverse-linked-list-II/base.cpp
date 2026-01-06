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

ListNode *createList(const vector<int> &nums)
{
  ListNode dummy;
  ListNode *tail = &dummy;

  for (const int &v : nums)
  {
    tail->next = new ListNode(v);
    tail = tail->next;
  }

  return dummy.next;
}

class Solution
{
public:
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    if (!head || left == right)
      return head;

    int idx = 0;

    ListNode dummy = ListNode(0);
    dummy.next = head;

    ListNode *crr = dummy.next, *pre = &dummy;
    ListNode *seg_before = &dummy, *seg_head, *seg_tail;

    while (crr)
    {
      idx++;
      ListNode *next = crr->next;

      if (idx == left)
      {
        seg_before = pre;
        seg_head = crr;
      }
      else if (idx == right)
      {
        crr->next = pre;
        seg_before->next = crr;
        seg_head->next = next;
      }
      else if (idx > left)
      {
        crr->next = pre;
      }

      pre = crr;
      crr = next;
    }

    return dummy.next;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  auto head = createList(nums);

  Solution *sol = new Solution;
  sol->reverseBetween(head, 2, 4);
  return 0;
}