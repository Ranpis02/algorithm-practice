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
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (!head || !head->next || k == 0)
      return head;

    ListNode *p = head;
    ListNode *tail = head;

    int len = 0;

    while (p)
    {
      tail = p;
      len++;
      p = p->next;
    }

    int n = k % len;

    if (n == 0)
      return head;

    p = head;
    for (int i = 0; i < len - n - 1; i++)
    {
      p = p->next;
    }

    tail->next = head;
    head = p->next;
    p->next = nullptr;

    return head;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};

  ListNode *head = createList(nums);

  Solution *sol = new Solution;
  sol->rotateRight(head, 2);

  return 0;
}