#include <iostream>
#include <queue>

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

/**
 * Solution: postorder + dp
 */
struct Status
{
  int notRob; // the not-rob state
  int rob;    // the rob state
};

class Solution
{
public:
  int rob(TreeNode *root)
  {
    Status ans = robNode(root);
    return max(ans.notRob, ans.rob);
  }

  Status robNode(TreeNode *root)
  {
    if (!root)
      return {0, 0};

    Status left = robNode(root->left);
    Status right = robNode(root->right);

    int notRob = max(left.notRob, left.rob) + max(right.notRob, right.rob);
    int rob = root->val + left.notRob + right.notRob;

    return {notRob, rob};
  }
};
int main()
{

  return 0;
}