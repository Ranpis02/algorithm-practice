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
    if (nums[i])
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

/**
 * Check the inorder traversal result (x)
 * Such as, [1, 2, 2, 2, null, 2]
 */
class Solution_EA
{
public:
  bool isSymmetric(TreeNode *root)
  {
    vector<int> res;
    while (root)
    {
      if (root->left)
      {
        TreeNode *predecessor = root->left;

        while (predecessor->right && predecessor->right != root)
        {
          predecessor = predecessor->right;
        }

        if (!predecessor->right)
        {
          predecessor->right = root;
          root = root->left;
        }
        else
        {
          res.push_back(root->val);
          predecessor->right = nullptr;

          root = root->right;
        }
      }
      else
      {
        res.push_back(root->val);
        root = root->right;
      }
    }

    for (int i = 0, j = res.size() - 1; i < j; i++, j--)
    {
      if (res[i] == res[j])
        continue;
      else
        return false;
    }

    return true;
  }
};

class Solution
{
public:
  bool isSymmetric(TreeNode *root)
  {
        
  }
};

int main()
{
  vector<int> nums = {1, 2, 2, 3, 4, 4, 3};

  TreeNode *root = create(nums);

  return 0;
}