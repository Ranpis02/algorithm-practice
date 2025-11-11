#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

void printList(ListNode *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

class Solution
{
public:
  ListNode *sortList(ListNode *head)
  {
    vector<ListNode *> nums;
    while (head)
    {
      nums.emplace_back(head);
      head = head->next;
    }

    sort(nums.begin(), nums.end(), [](ListNode *a, ListNode *b)
         { return a->val < b->val; });

    ListNode *dummy = new ListNode();

    ListNode *p = dummy;
    for (ListNode *node : nums)
    {
      p->next = node;
      p = p->next;
    }
    p->next = nullptr;

    return dummy->next;
  }
};

int main()
{
  vector<int> nums = {4, 2, 1, 3};
  ListNode *head = createList(nums);
  Solution *s = new Solution;
  s->sortList(head);

  return 0;
}