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
    if (!head || !head->next)
      return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *mid = slow;
    ListNode *right = mid->next;
    mid->next = nullptr;

    return mergeSortedList(sortList(head), sortList(right));
  }

  ListNode *mergeSortedList(ListNode *headA, ListNode *headB)
  {
    ListNode *dummy = new ListNode();
    ListNode *p = dummy;

    while (headA && headB)
    {
      if (headA->val <= headB->val)
      {
        p->next = headA;
        headA = headA->next;
      }
      else
      {
        p->next = headB;
        headB = headB->next;
      }
      p = p->next;
    }

    p->next = headA ? headA : headB;

    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
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