#include <iostream>
#include <vector>
#include <stack>

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
    // if (!headA || !headB)
    //   return nullptr;

    stack<ListNode *> stA;
    stack<ListNode *> stB;
    while (headA)
    {
      stA.push(headA);
      headA = headA->next;
    }

    while (headB)
    {
      stB.push(headB);
      headB = headB->next;
    }

    ListNode *prev = nullptr;
    while (!stA.empty() && !stB.empty())
    {
      if (stA.top() == stB.top())
      {
        prev = stA.top();
        stA.pop();
        stB.pop();
      }
      else
      {
        return prev;
      }
    }

    return prev;
  }
};

int main()
{

  return 0;
}