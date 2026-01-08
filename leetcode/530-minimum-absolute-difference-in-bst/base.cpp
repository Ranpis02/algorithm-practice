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

TreeNode *createTree(const vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  vector<TreeNode *> nodes(nums.size(), nullptr);

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != -1)
      nodes[i] = new TreeNode(nums[i]);
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (!nodes[i])
      continue;
    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < nums.size())
      nodes[i]->left = nodes[leftIdx];
    if (rightIdx < nums.size())
      nodes[i]->right = nodes[rightIdx];
  }

  return nodes[0];
}

class Solution
{
private:
  int ans;
  TreeNode *pre;

public:
  int getMinimumDifference(TreeNode *root)
  {
    ans = INT_MAX;
    pre = nullptr;
    dfs(root);

    return ans;
  }

  void dfs(TreeNode *root)
  {
    if (!root)
      return;

    if (root->left)
      dfs(root->left);

    if (pre != nullptr)
    {
      ans = min(ans, abs(root->val - pre->val));
    }
    pre = root;

    if (root->right)
      dfs(root->right);
  }
};

int main()
{
  vector<int> nums = {236, 104, 701, -1, 227, -1, 911};

  auto root = createTree(nums);

  Solution *sol = new Solution;
  sol->getMinimumDifference(root);


  return 0;
}