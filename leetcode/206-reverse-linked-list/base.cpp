#include <iostream>
#include <stack>
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
  ListNode *reverseList(ListNode *head)
  {
    stack<ListNode *> st;

    while (head)
    {
      st.push(head);
      head = head->next;
    }

    ListNode *dummy = new ListNode();
    ListNode *p = dummy;
    while (!st.empty())
    {
      p->next = st.top();
      p = p->next;
      st.pop();
    }

    /*
      Caution: It's essential to set the last node's `next` pointer to nullptr.
      Otherwise, the last node may still point its original next node,
      resulting in a cyclic list or an infinite loop during traversal.
    */
    p->next = nullptr;

    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head = createList(nums);
  Solution *s = new Solution;
  ListNode *ans = s->reverseList(head);

  printList(ans);
  return 0;
}