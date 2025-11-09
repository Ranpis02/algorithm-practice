#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *createList(const vector<int> &nums)
{
  ListNode *dummy = new ListNode(0);
  ListNode *p = dummy;

  for (const int &v : nums)
  {
    p->next = new ListNode(v);
    p = p->next;
  }

  ListNode *ans = dummy->next;
  delete dummy;
  return ans;
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *dummy = new ListNode(0);

    ListNode *p = dummy;

    while (list1 && list2)
    {
      if (list1->val <= list2->val)
      {
        p->next = list1;
        list1 = list1->next;
      }
      else
      {
        p->next = list2;
        list2 = list2->next;
      }
      p = p->next;
    }

    // Simplify the following code snippet by connecting the non-null node directly
    /*     while (list1)
        {
          p->next = list1;
          list1 = list1->next;
          p = p->next;
        }

        while (list2)
        {
          p->next = list2;
          list2 = list2->next;
          p = p->next;
        } */

    p->next = list1 == nullptr ? list2 : list1;

    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
  }
};

int main()
{
  vector<int> nums1 = {1, 2, 4};
  vector<int> nums2 = {1, 3, 4};

  ListNode *head1 = createList(nums1);
  ListNode *head2 = createList(nums2);

  Solution *s = new Solution;
  ListNode *head3 = s->mergeTwoLists(head1, head2);

  printList(head3);
  return 0;
}