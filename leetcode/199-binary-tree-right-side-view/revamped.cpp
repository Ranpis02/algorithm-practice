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

      for (int i = 0; i < n; i++)
      {
        TreeNode *crr = q.front();
        q.pop();

        if (i == n - 1)
          ans.push_back(crr->val);
        if (crr->left)
          q.push(crr->left);
        if (crr->right)
          q.push(crr->right);
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}