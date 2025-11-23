#include <iostream>

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
private:
  int diameter = 0;

public:
  int diameterOfBinaryTree(TreeNode *root)
  {
    getDepth(root);
    return diameter;
  }

  int getDepth(TreeNode *root)
  {
    if (!root)
      return 0;

    int left = getDepth(root->left) + 1;
    int right = getDepth(root->right) + 1;

    diameter = max(left + right - 2, diameter);

    return max(left, right);
  }
};

int main()
{

  return 0;
}