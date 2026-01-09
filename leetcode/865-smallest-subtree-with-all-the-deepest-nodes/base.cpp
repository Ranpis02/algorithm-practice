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
  TreeNode *subtreeWithAllDeepest(TreeNode *root)
  {
    auto ans = dfs(root);
    return ans.second;
  }

  pair<int, TreeNode *> dfs(TreeNode *root)
  {
    if (!root)
      return {0, nullptr};

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    if (left.first > right.first)
    {
      return {left.first + 1, left.second};
    }
    else if (left.first < right.first)
    {
      return {right.first + 1, right.second};
    }
    else
    {
      return {left.first + 1, root};
    }
  }
};

int main()
{

  return 0;
}