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

class Solution
{
private:
  int maxSum = INT_MIN;

public:
  int maxPathSum(TreeNode *root)
  {
    maxGain(root);
    return maxSum;
  }

  int maxGain(TreeNode *root)
  {
    if (!root)
      return 0;

    int leftGain = max(maxGain(root->left), 0);
    int rightGain = max(maxGain(root->right), 0);

    maxSum = max(leftGain + rightGain + root->val, maxSum);

    return max((root->val + max(leftGain, rightGain)), 0);
  }
};

int main()
{

  return 0;
}