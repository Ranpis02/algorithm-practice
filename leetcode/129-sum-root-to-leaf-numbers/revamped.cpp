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

class Solution
{
public:
  int sumNumbers(TreeNode *root)
  {
    return dfs(root, 0);
  }

  int dfs(TreeNode *root, int sum)
  {
    if (!root)
      return 0;

    int crr = sum * 10 + root->val;

    if (!root->left && !root->right)
      return crr;

    return dfs(root->left, crr) + dfs(root->right, crr);
  }
};

int main()
{

  return 0;
}