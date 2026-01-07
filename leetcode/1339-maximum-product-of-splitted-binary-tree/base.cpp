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
public:
  int maxProduct(TreeNode *root)
  {
    getSubTreeSum(root);

    int total = accumulate(allSums.begin(), allSums.end(), 0);

    long long ans = 0;
    int n = allSums.size();

    for (int i = 0; i < n - 1; i++)
    {
      ans = max(ans, allSums[i] * (allSums[n - 1] - allSums[i]));
    }

    return ans % MOD;
  }

  long long getSubTreeSum(TreeNode *root)
  {
    if (!root)
      return 0;

    long long leftSum = getSubTreeSum(root->left);
    long long rightSum = getSubTreeSum(root->right);

    long long totalSum = leftSum + rightSum + root->val;

    allSums.push_back(totalSum);

    return totalSum;
  }

private:
  static constexpr int MOD = 1e9 + 7;

  vector<long long> allSums;
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6};

  auto root = create(nums);
  Solution *sol = new Solution;
  sol->getSubTreeSum(root);

  return 0;
}