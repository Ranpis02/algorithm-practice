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
    calculate(root, 0);
    return ans;
  }

  void calculate(TreeNode *root, int sum)
  {
    if (!root)
      return;

    int crr = sum * 10 + root->val;

    if (!root->left && !root->right)
    {
      ans += crr;
    }

    if (root->left)
      calculate(root->left, crr);
    if (root->right)
      calculate(root->right, crr);
  }

private:
  int ans = 0;
};

int main()
{

  return 0;
}