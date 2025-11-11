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
  bool isPalindrome(ListNode *head)
  {
    stack<ListNode *> st;

    ListNode *p = head;
    while (p)
    {
      st.push(p);
      p = p->next;
    }

    int size = st.size();
    for (int i = 0; i < size / 2; i++)
    {
      if (head->val == st.top()->val)
      {
        head = head->next;
        st.pop();
      }
      else
        return false;
    }
    return true;
  }
};

int main()
{

  vector<int> nums = {1, 1, 2, 1};
  ListNode *head = createList(nums);
  Solution *s = new Solution;
  s->isPalindrome(head);

  return 0;
}