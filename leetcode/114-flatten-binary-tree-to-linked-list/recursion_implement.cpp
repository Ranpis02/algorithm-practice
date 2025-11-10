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
  void flatten(TreeNode *root)
  {
    if (!root)
      return;

    flatten(root->left);
    flatten(root->right);

    TreeNode *leftNode = root->left;
    TreeNode *rightNode = root->right;

    if (root->left)
    {
      root->right = leftNode;
      while (leftNode->right)
      {
        leftNode = leftNode->right;
      }
      leftNode->right = rightNode;
    }
    root->left = nullptr;
  }
};

int main()
{
  vector<int> nums = {1, 2, 5, 3, 4, -1, 6};
  TreeNode *root = createTree(nums);

  Solution *s = new Solution;
  s->flatten(root);

  return 0;
}