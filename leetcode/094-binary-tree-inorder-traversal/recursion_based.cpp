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
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    if (root)
    {
      vector<int> l = inorderTraversal(root->left);
      vector<int> r = inorderTraversal(root->right);

      ans.reserve(l.size() + r.size() + 1);

      ans.insert(ans.end(), l.begin(), l.end());
      ans.insert(ans.end(), root->val);
      ans.insert(ans.end(), r.begin(), r.end());
    }

    return ans;
  }
};
int main()
{

  return 0;
}