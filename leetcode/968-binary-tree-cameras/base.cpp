#include <bits/stdc++.h>

using namespace std;

enum State
{
  UNCOVERED = 0,
  COVERED = 1,
  CAMERA = 2
};

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *create(vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  int n = nums.size();
  vector<TreeNode *> nodes(n, nullptr);

  for (int i = 0; i < n; i++)
  {
    if (nums[i] != -1)
    {
      nodes[i] = new TreeNode(nums[i]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (!nodes[i])
      continue;

    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < n)
      nodes[i]->left = nodes[leftIdx];
    if (rightIdx < n)
      nodes[i]->right = nodes[rightIdx];
  }

  return nodes[0];
}

class Solution
{
private:
  int ans = 0;

public:
  int minCameraCover(TreeNode *root)
  {
    if (dfs(root) == UNCOVERED)
    {
      ans++;
    }

    return ans;
  }

  /**
   * 0: uncovered
   * 1: convered
   * 2: has camera
   */
  int dfs(TreeNode *root)
  {
    if (!root)
      return COVERED;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == UNCOVERED || right == UNCOVERED)
    {
      ans++;
      return CAMERA;
    }

    if (left == CAMERA || right == CAMERA)
    {
      return COVERED;
    }

    return UNCOVERED;
  }
};

int main()
{

  return 0;
}