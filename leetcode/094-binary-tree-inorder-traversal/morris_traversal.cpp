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

/**
 * Core idea: establish a thread from the predecessor to the current node.
 */
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;

    while (root)
    {
      if (root->left)
      {
        TreeNode *predecessor = root->left;

        while (predecessor->right && predecessor->right != root)
        {
          predecessor = predecessor->right;
        }

        if (predecessor->right == nullptr)
        {
          // Establish the connection between the right subtree and the root.
          predecessor->right = root;
          root = root->left;
        }
        else
        {
          // The left subtree has been traversed, and the link need to be broken.
          ans.push_back(root->val);
          predecessor->right = nullptr;
          root = root->right;
        }
      }
      else
      {
        // There is no left subtree, process the current node.
        ans.push_back(root->val);
        root = root->right;
      }
    }

    return ans;
  }
};
int main()
{

  return 0;
}