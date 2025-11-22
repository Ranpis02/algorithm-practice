#include <iostream>
#include <vector>
#include <unordered_map>

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

void preorder(TreeNode *root)
{
  if (root)
  {
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

class Solution
{
private:
  int ans = 0;

public:
  int pathSum(TreeNode *root, int targetSum)
  {
    long long acc = 0;
    unordered_map<long long, int> mp;
    mp[0] = 1;
    traversal(root, targetSum, mp, acc);

    return ans;
  }

  void traversal(TreeNode *root, int targetSum, unordered_map<long long, int> &mp, long long acc)
  {
    if (!root)
      return;

    acc += root->val;
    if (mp.count(acc - targetSum))
      ans += mp[acc - targetSum];
    mp[acc]++;

    traversal(root->left, targetSum, mp, acc);
    traversal(root->right, targetSum, mp, acc);

    // Backtrack: remove current sum from map before returning.
    mp[acc]--;
  }
};

int main()
{
  vector<int> nums = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
  TreeNode *root = createTree(nums);
  cout << "Orginal data: ";
  preorder(root);

  cout << endl;

  Solution *s = new Solution;
  // s->pathSum(root, 22);

  // cout << "After accumulation: ";
  // preorder(root);

  // cout << endl;

  return 0;
}