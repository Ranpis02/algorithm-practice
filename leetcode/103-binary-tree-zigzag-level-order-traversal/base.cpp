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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    if (!root)
      return {};

    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> ans;

    bool flag = false;
    while (!q.empty())
    {
      int n = q.size();
      vector<int> layer;

      for (int i = 0; i < n; i++)
      {
        TreeNode *crr = q.front();
        q.pop();

        if (crr->left)
          q.push(crr->left);
        if (crr->right)
          q.push(crr->right);

        layer.push_back(crr->val);
      }

      if (flag)
        reverse(layer.begin(), layer.end());

      ans.push_back(layer);
      flag = !flag;
    }

    return ans;
  }
};

int main()
{

  return 0;
}