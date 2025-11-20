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

class Solution
{
public:
  int maxDepth(TreeNode *root)
  {
    if (!root)
      return 0;
    return max(getDepth(root->left, 1), getDepth(root->right, 1));
  }

  int getDepth(TreeNode *root, int height)
  {
    if (!root)
      return height;

    if (root->left && root->right)
      return max(getDepth(root->left, height + 1), getDepth(root->right, height + 1));
    else if (root->left && !root->right)
      return getDepth(root->left, height + 1);
    else if (!root->left && root->right)
      return getDepth(root->right, height + 1);
    else
    {
      return height + 1;
    }
  }
};

int main()
{

  return 0;
}