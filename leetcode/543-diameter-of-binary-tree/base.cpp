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

struct Node
{
  int leftHeight;
  int rightHeight;
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

  Node getDepth(TreeNode *root)
  {
    if (!root)
      return {0, 0};

    int leftHeight, rightHeight;

    Node left = getDepth(root->left);
    leftHeight = max(left.leftHeight, left.rightHeight) + 1;

    Node right = getDepth(root->right);
    rightHeight = max(right.leftHeight, right.rightHeight) + 1;

    diameter = max(leftHeight + rightHeight - 2, diameter);
    return {leftHeight, rightHeight};
  }
};

int main()
{

  return 0;
}