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
  ListNode dummy = ListNode(0);
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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (!head || k == 1)
      return head;

    ListNode dummy = ListNode(0);
    dummy.next = head;

    ListNode *p = &dummy;
    int cnt = 0;
    while (p->next)
    {
      cnt++;
      p = p->next;
    }

    int reversed_num = k * (cnt / k);

    p = head;

    int idx = 1;
    ListNode *seg_head_before = &dummy;
    ListNode *seg_head = head;

    ListNode *prev = &dummy;
    ListNode *next;

    while (idx <= reversed_num)
    {
      next = p->next;

      if (idx % k == 1)
      {
        seg_head = p;
      }
      else
      {
        p->next = prev;
      }

      if (idx % k == 0)
      {
        seg_head_before->next = p;

        seg_head_before = seg_head;

        seg_head->next = next;
      }

      prev = p;
      p = next;
      idx++;
    }

    return dummy.next;
  }
};
int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 2;

  ListNode *head = create(nums);
  Solution *sol = new Solution;
  sol->reverseKGroup(head, 2);

  return 0;
}