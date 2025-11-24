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
private:
  int acc = 0;

public:
  TreeNode *convertBST(TreeNode *root)
  {
    if (root)
    {
      convertBST(root->right);
      acc += root->val;
      root->val = acc;
      convertBST(root->left);
    }
    return root;
  }
};
int main()
{

  return 0;
}