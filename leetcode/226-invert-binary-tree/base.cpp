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
  TreeNode *invertTree(TreeNode *root)
  {
    if (!root)
      return nullptr;

    TreeNode *left = root->left;

    root->left = invertTree(root->right);
    root->right = invertTree(left);

    return root;
  }
};

using namespace std;

int main()
{

  return 0;
}