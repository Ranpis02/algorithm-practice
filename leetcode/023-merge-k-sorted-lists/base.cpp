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
  /**
   * Sequential Merge
   */
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.size() == 0)
      return nullptr;
    ListNode *p = nullptr;
    for (int i = 0; i < lists.size(); i++)
    {
      p = mergeTwoLists(p, lists[i]);
    }

    return p;
  }

  /**
   * Pairwise merge the linked list
   */
  ListNode *divideAndConquer(vector<ListNode *> &lists)
  {
    return merge(lists, 0, lists.size() - 1);
  }

  ListNode *merge(const vector<ListNode *> &lists, int l, int r)
  {
    if (l == r)
      return lists[l];
    if (l > r)
      return nullptr;
    int mid = ((r - l) >> 1) + l;

    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
  }

private:
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

    p->next = list1 == nullptr ? list2 : list1;

    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
  }
};
int main()
{

  return 0;
}