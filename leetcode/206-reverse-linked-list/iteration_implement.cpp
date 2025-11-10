#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *crr = head;

    while (crr)
    {
      ListNode *node = crr->next;
      crr->next = prev;
      prev = crr;
      crr = node;
    }

    return crr;
  }
};

int main()
{
}