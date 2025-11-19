#include <iostream>
#include <vector>
#include <stack>

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

    stack<TreeNode *> st;

    while (root || !st.empty())
    {
      while (root)
      {
        st.push(root);
        root = root->left;
      }

      TreeNode *crr = st.top();
      ans.push_back(crr->val);
      st.pop();

      root = crr->right;
    }

    return ans;
  }
};
int main()
{
  vector<int> t = {};
  return 0;
}