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

TreeNode *create(vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  int n = nums.size();
  vector<TreeNode *> nodes(n);

  for (int i = 0; i < n; i++)
  {
    if (nums[i] == -1)
      continue;
    nodes[i] = new TreeNode(nums[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (!nodes[i])
      continue;

    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < n)
      nodes[i]->left = nodes[leftIdx];
    if (rightIdx < n)
      nodes[i]->right = nodes[rightIdx];
  }

  return nodes[0];
}

class Solution
{
public:
  bool isSymmetric(TreeNode *root)
  {
    if (!root)
      return true;

    return isBothSymetric(root->left, root->right);
  }

  bool isBothSymetric(TreeNode *tree1, TreeNode *tree2)
  {
    if (!tree1 && !tree2)
      return true;
    if (!tree1 || !tree2)
      return false;

    // if (tree1->val == tree2->val)
    return tree1->val == tree2->val && isBothSymetric(tree1->right, tree2->left) && isBothSymetric(tree1->left, tree2->right);
    // else
    // return false;
  }
};

int main()
{
  vector<int> nums = {1, 2, 2, 3, 4, 4, 3};
  TreeNode *root = create(nums);
  Solution *s = new Solution;
  s->isSymmetric(root);

  return 0;
}