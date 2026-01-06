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

TreeNode *create(vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  int n = nums.size();
  vector<TreeNode *> nodes(n, nullptr);
  for (int i = 0; i < n; i++)
  {
    if (nums[i] != -1)
      nodes[i] = new TreeNode(nums[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (!nodes[i])
      continue;
    int leftIdx = i * 2 + 1;
    int rightIdx = i * 2 + 2;

    if (leftIdx < n)
      nodes[i]->left = nodes[leftIdx];
    if (rightIdx < n)
      nodes[i]->right = nodes[rightIdx];
  }

  return nodes[0];
}

class Solution
{
public:
  int maxLevelSum(TreeNode *root)
  {
    if (!root)
      return 0;

    queue<TreeNode *> q;
    long long maxVal = INT_MIN;
    int ans = 0, layer = 0;

    q.push(root);

    while (!q.empty())
    {
      int n = q.size();
      long long sum = 0;
      layer++;

      for (int i = 0; i < n; i++)
      {
        TreeNode *t = q.front();
        q.pop();

        sum += t->val;

        if (t->left)
          q.push(t->left);

        if (t->right)
          q.push(t->right);
      }

      if (sum > maxVal)
      {
        maxVal = sum;
        ans = layer;
      }
    }

    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 7, 0, 7, -8, -1, -1};

  auto root = create(nums);
  Solution *sol = new Solution;
  sol->maxLevelSum(root);

  return 0;
}