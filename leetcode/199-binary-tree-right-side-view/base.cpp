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
  vector<int> rightSideView(TreeNode *root)
  {
    if (!root)
      return {};

    queue<TreeNode *> q;
    q.push(root);

    vector<int> ans;
    while (!q.empty())
    {
      int n = q.size();
      for (int i = 0; i < n - 1; i++)
      {
        TreeNode *crr = q.front();
        q.pop();

        if (crr->left)
          q.push(crr->left);
        if (crr->right)
          q.push(crr->right);
      }

      TreeNode *crr = q.front();
      if (crr->left)
        q.push(crr->left);
      if (crr->right)
        q.push(crr->right);

      q.pop();

      ans.push_back(crr->val);
    }

    return ans;
  }
};

int main()
{

  return 0;
}