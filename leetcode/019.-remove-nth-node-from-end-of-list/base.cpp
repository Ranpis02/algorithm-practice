#include <iostream>
#include <string>
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode dummy = ListNode(0);
    dummy.next = head;
    ListNode *p = &dummy, *q = &dummy;

    int total = 0;
    // Count the total number of the linked list
    while (p->next)
    {
      total++;
      p = p->next;
    }

    int i = total - n + 1;

    while (q->next)
    {
      --i;
      if (i == 0)
      {
        ListNode *tmp = q->next;
        q->next = tmp->next;
        delete tmp;
        break;
      }
      q = q->next;
    }

    return dummy.next;
  }
};

int main()
{
  vector<int> a = {1, 2, 3, 4, 5};

  ListNode *head = createList(a);

  Solution *s = new Solution;

  s->removeNthFromEnd(head, 2);

  return 0;
}