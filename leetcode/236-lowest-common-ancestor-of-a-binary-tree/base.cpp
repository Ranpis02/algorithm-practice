#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *createTree(const vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  vector<TreeNode *> nodes(nums.size(), nullptr);

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != -1)
      nodes[i] = new TreeNode(nums[i]);
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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root || root == p || root == q)
    {
      return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
    {
      return root;
    }

    if (left)
      return left;

    return right;
  }
};
int main()
{
  vector<int> nums = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};

  vector<TreeNode *> nodes(nums.size(), nullptr);

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != -1)
      nodes[i] = new TreeNode(nums[i]);
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

  Solution *s = new Solution;
  s->lowestCommonAncestor(nodes[0], nodes[1], nodes[10]);

  return 0;
}