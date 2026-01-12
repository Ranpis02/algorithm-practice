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
    ListNode lessDummy(0);
    ListNode otherDummy(0);

    ListNode *lessCrr = &lessDummy;
    ListNode *otherCrr = &otherDummy;

    ListNode *crr = head;

    while (crr)
    {
      if (crr->val < x)
      {
        lessCrr->next = crr;
        lessCrr = lessCrr->next;
      }
      else
      {
        otherCrr->next = crr;
        otherCrr = otherCrr->next;
      }

      crr = crr->next;
    }

    lessCrr->next = otherDummy.next;

    otherCrr->next = nullptr;

    return lessDummy.next;
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