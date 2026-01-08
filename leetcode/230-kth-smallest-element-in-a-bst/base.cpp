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
  int idx = 0;
  int ans = -1;

public:
  int kthSmallest(TreeNode *root, int k)
  {
    dfs(root, k);

    return ans;
  }

  void dfs(TreeNode *root, int k)
  {
    if (!root || idx >= k)
      return;

    if (root->left)
      dfs(root->left, k);

    idx++;
    if (idx == k)
    {
      ans = root->val;
      return;
    }

    if (root->right)
      dfs(root->right, k);
  }
};

int main()
{

  return 0;
}