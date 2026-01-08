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
public:
  int kthSmallest(TreeNode *root, int k)
  {
    if (!root)
      return -1;

    stack<TreeNode *> st;
    // st.push(root);

    while (root != nullptr || !st.empty())
    {
      while (root)
      {
        st.push(root);
        root = root->left;
      }

      root = st.top();
      st.pop();
      k--;

      if (k == 0)
        return root->val;

      root = root->right;
    }

    return -1;
  }
};

int main()
{
  vector<int> nums = {5, 3, 6, 2, 4, -1, -1, 1};

  auto root = createTree(nums);
  Solution *sol = new Solution;
  sol->kthSmallest(root, 6);

  return 0;
}