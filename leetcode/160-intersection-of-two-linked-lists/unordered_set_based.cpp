#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    unordered_set<ListNode *> seen;

    while (headA)
    {
      seen.insert(headA);
      headA = headA->next;
    }

    while (headB)
    {
      if (seen.count(headB))
      {
        return headB;
      }
      else
      {
        headB = headB->next;
      }
    }

    return nullptr;
  }
};

int main()
{

  return 0;
}