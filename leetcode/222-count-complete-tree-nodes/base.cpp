#include <bits/stdc++.h>

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
  int countNodes(TreeNode *root)
  {
    if (!root)
      return 0;

    TreeNode *l = root;
    TreeNode *r = root;

    int lDepth = 0, rDepth = 0;

    while (l)
    {
      lDepth++;
      l = l->left;
    }

    while (r)
    {
      rDepth++;
      r = r->right;
    }

    if (lDepth == rDepth)
      return (1 << lDepth) - 1;

    int ans = 0;
    if (root->left)
      ans += countNodes(root->left);
    if (root->right)
      ans += countNodes(root->right);

    return ans + 1;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  TreeNode *root = createTree(nums);

  Solution *sol = new Solution;
  sol->countNodes(root);

  return 0;
}