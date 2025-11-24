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
  TreeNode *convertBST(TreeNode *root)
  {
    vector<TreeNode *> nodes;

    dfs(root, nodes);

    int ans = 0;
    for (int i = nodes.size() - 1; i >= 0; i--)
    {
      ans += nodes[i]->val;
      nodes[i]->val = ans;
    }

    return root;
  }

  void dfs(TreeNode *root, vector<TreeNode *> &nodes)
  {
    if (root)
    {
      dfs(root->left, nodes);
      nodes.push_back(root);
      dfs(root->right, nodes);
    }
  }
};
int main()
{

  return 0;
}