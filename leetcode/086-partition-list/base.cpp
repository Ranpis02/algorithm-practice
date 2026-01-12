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
  ListNode *partition(ListNode *head, int x)
  {
    vector<ListNode *> lessNodes;
    vector<ListNode *> otherNodes;

    ListNode *p = head;

    while (p)
    {
      if (p->val < x)
      {
        lessNodes.push_back(p);
      }
      else
      {
        otherNodes.push_back(p);
      }
      p = p->next;
    }

    ListNode dummy(0);
    p = &dummy;

    for (auto &node : lessNodes)
    {
      p->next = node;
      p = p->next;
    }

    int n = otherNodes.size();
    for (int i = 0; i < n; i++)
    {
      p->next = otherNodes[i];
      p = p->next;
    }

    p->next = nullptr;

    return dummy.next;
  }
};

int main()
{
  vector<int> nums = {1, 4, 3, 2, 5, 2};
  auto head = createList(nums);

  Solution *sol = new Solution;
  sol->partition(head, 3);

  return 0;
}