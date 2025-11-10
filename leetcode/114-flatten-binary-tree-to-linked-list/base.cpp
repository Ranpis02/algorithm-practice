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

TreeNode *createTree(const vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  int len = nums.size();
  vector<TreeNode *> node(len, nullptr);

  for (int i = 0; i < len; i++)
  {
    if (nums[i] != -1)
      node[i] = new TreeNode(nums[i]);
  }

  for (int i = 0; i < len; i++)
  {
    if (!node[i])
      continue;

    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < len)
      node[i]->left = node[leftIdx];
    if (rightIdx < len)
      node[i]->right = node[rightIdx];
  }

  return node[0];
}

class Solution
{
public:
  void flatten(TreeNode *root)
  {
    vector<TreeNode *> nodes;
    preorder(root, nodes);

    TreeNode *crr = root;
    for (int i = 1; i < nodes.size(); i++)
    {
      crr->right = nodes[i];
      crr->left = nullptr;
      crr = crr->right;
    }

    // x, Warning: the following assignment only redirects the local copy of `root`(won't change the caller's root)
    // root = nodes[0];
  }

private:
  // Caution: note the use of `&`
  void preorder(TreeNode *root, vector<TreeNode *> &nodes)
  {
    if (root)
    {
      nodes.push_back(root);
      preorder(root->left, nodes);
      preorder(root->right, nodes);
    }
  }
};

int main()
{
  vector<int> nums = {1, 2, 5, 3, 4, -1, 6};

  TreeNode *root = createTree(nums);

  // Solution *s = new Solution;
  // s->flatten(root);

  return 0;
}