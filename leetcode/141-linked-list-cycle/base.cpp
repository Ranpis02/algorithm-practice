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
  bool hasCycle(ListNode *head)
  {
    unordered_set<ListNode *> seen;

    while (head)
    {
      if (seen.count(head))
        return true;
      else
      {
        seen.insert(head);
        head = head->next;
      }
    }

    return false;
  }
};
int main()
{

  return 0;
}