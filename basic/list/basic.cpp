#include <iostream>
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

/**
 * @brief Creates a singly linked list from a given vector of integers.
 */
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

/**
 * @brief Inserts a new node after the first node that has the value 'target'.
 *
 * @param head   A pointer to the head node of the linked list.
 * @param target The value to search for in the list.
 * @param val    The value of the new node to be inserted.
 *
 */
void insertNode(ListNode *head, int target, int val)
{
  for (ListNode *p = head; p; p = p->next)
  {
    if (p->val == target)
    {
      ListNode *node = new ListNode(val);

      node->next = p->next;
      p->next = node;
      break;
    }
  }
}

/**
 * @brief Deletes the first node in the list that has the value 'target'.
 */
ListNode *deleteNode(ListNode *head, int target)
{
  ListNode dummy = ListNode(0);
  dummy.next = head;

  ListNode *p = &dummy;

  while (p->next)
  {
    if (p->next->val == target)
    {
      ListNode *tmp = p->next;
      p->next = tmp->next;
      delete tmp;
      break;
    }
    p = p->next;
  }

  return dummy.next;
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

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  ListNode *head = createList(nums);
  printList(head);

  insertNode(head, 3, 6);

  printList(head);

  deleteNode(head, 6);

  printList(head);

  return 0;
}