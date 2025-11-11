#include <iostream>
#include <vector>
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
  ListNode *dummy = new ListNode();

  ListNode *p = dummy;
  for (const int &n : nums)
  {
    p->next = new ListNode(n);
    p = p->next;
  }
  ListNode *head = dummy->next;
  delete dummy;
  return head;
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
  bool isPalindrome(ListNode *head)
  {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *pivot = reverseLinkedList(slow);

    while (head && pivot)
    {
      if (head->val == pivot->val)
      {
        head = head->next;
        pivot = pivot->next;
      }
      else
      {
        return false;
      }
    }

    return true;
  }

  ListNode *reverseLinkedList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *p = head;
    while (p)
    {
      ListNode *next = p->next;
      p->next = prev;
      prev = p;
      p = next;
    }

    return prev;
  }
};
int main()
{
  vector<int> nums = {1, 2, 2, 1};
  ListNode *head = createList(nums);

  Solution *s = new Solution;
  s->isPalindrome(head);

  return 0;
}