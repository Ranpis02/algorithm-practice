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
    if (!headA || !headB)
      return nullptr;

    ListNode *pA = headA;
    ListNode *pB = headB;

    // If no interseciotn node, pA = pB = nullptr
    while (pA != pB)
    {
      pA = pA ? pA->next : headB;
      pB = pB ? pB->next : headA;
    }

    return pA;
  }
};

int main()
{
  return 0;
}