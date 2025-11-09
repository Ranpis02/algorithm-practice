#include <iostream>
#include <string>
#include <vector>
#include <stack>

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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    stack<ListNode *> s;
    ListNode *dummy = new ListNode(0, head);

    ListNode *p = dummy;
    // Caution: make sure to load a dummy node for safety
    while (p)
    {
      s.push(p);
      p = p->next;
    }

    for (int i = 0; i < n; i++)
    {
      s.pop();
    }

    ListNode *prev = s.top();

    ListNode *tmp = prev->next;
    prev->next = tmp->next;
    delete tmp;

    ListNode *ans = dummy->next;

    delete dummy;
    return ans;
  }
};

int main()
{
  vector<int> nums = {1};
  ListNode *head = createList(nums);

  Solution *s = new Solution;
  ListNode *res = s->removeNthFromEnd(head, 1);

  printList(res);
  return 0;
}