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
    bool isOrderLeft = true;
    vector<vector<int>> ans;

    while (!q.empty())
    {
      int n = q.size();

      vector<int> layer(n);
      for (int i = 0; i < n; i++)
      {
        TreeNode *crr = q.front();
        q.pop();

        int idx = isOrderLeft ? i : n - i - 1;
        layer[idx] = crr->val;

        if (crr->left)
          q.push(crr->left);
        if (crr->right)
          q.push(crr->right);
      }

      ans.push_back(layer);
      isOrderLeft = !isOrderLeft;
    }

    return ans;
  }
};

int main()
{

  return 0;
}