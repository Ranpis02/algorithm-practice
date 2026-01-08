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
  vector<int> ans;

public:
  vector<int> rightSideView(TreeNode *root)
  {
    ans.clear();
    dfs(root, 0);

    return ans;
  }

  void dfs(TreeNode *root, int depth)
  {
    if (!root)
      return;

    // Only when `ans.size() == depth`, does it indicates that the current level is being visited for the first time.
    if (depth == ans.size())
      ans.push_back(root->val);

    dfs(root->right, depth + 1);
    dfs(root->left, depth + 1);
  }
};

int main()
{

  return 0;
}