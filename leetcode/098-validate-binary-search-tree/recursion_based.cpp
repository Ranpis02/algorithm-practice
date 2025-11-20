#include <iostream>
#include <vector>

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

TreeNode *create(const vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  int n = nums.size();
  vector<TreeNode *> nodes(n);

  for (int i = 0; i < n; i++)
  {
    if (nums[i] == -1)
      continue;
    nodes[i] = new TreeNode(nums[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (nodes[i] == nullptr)
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
public:
  bool isValidBST(TreeNode *root)
  {
    return isValid(root, LLONG_MIN, LLONG_MAX);
  }

  bool isValid(TreeNode *root, long long lower, long long upper)
  {
    if (root)
    {
      if (root->val >= upper || root->val <= lower)
        return false;

      return isValid(root->left, lower, root->val) && isValid(root->right, root->val, upper);
    }

    return true;
  }
};

int main()
{
  vector<int> nums = {2, 2, 2};

  return 0;
}