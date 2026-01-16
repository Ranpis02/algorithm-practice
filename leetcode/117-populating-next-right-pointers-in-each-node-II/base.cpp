#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

Node *createTree(const vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  vector<Node *> nodes(nums.size(), nullptr);

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != -1)
      nodes[i] = new Node(nums[i]);
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (!nodes[i])
      continue;
    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < nums.size())
      nodes[i]->left = nodes[leftIdx];
    if (rightIdx < nums.size())
      nodes[i]->right = nodes[rightIdx];
  }

  return nodes[0];
}
class Solution
{
public:
  Node *connect(Node *root)
  {
    if (!root)
      return nullptr;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      Node dummy(0);
      Node *crr = &dummy;

      for (int i = 0; i < n; i++)
      {
        Node *top = q.front();
        q.pop();

        if (top->left)
          q.push(top->left);
        if (top->right)
          q.push(top->right);

        crr->next = top;
        crr = crr->next;
      }
    }

    return root;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, -1, 7};
  Node *root = createTree(nums);

  Solution *sol = new Solution;
  sol->connect(root);

  return 0;
}