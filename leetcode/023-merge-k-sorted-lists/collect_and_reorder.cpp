#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

// ListNode *createList(const vector<int> &nums)
// {
//   ListNode *dummy = new ListNode(0);
//   ListNode *p = dummy;

//   for (const int &v : nums)
//   {
//     p->next = new ListNode(v);
//     p = p->next;
//   }

//   ListNode *ans = dummy->next;
//   delete dummy;
//   return ans;
// }

// void printList(ListNode *head)
// {
//   while (head)
//   {
//     cout << head->val << " ";
//     head = head->next;
//   }
//   cout << endl;
// }

class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    vector<int> nums;
    for (ListNode *list : lists)
    {
      while (list)
      {
        nums.push_back(list->val);
        list = list->next;
      }
    }

    sort(nums.begin(), nums.end());
    return createList(nums);
  }

private:
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
};
int main()
{

  return 0;
}