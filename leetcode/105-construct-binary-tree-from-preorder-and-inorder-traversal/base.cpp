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

class Solution
{
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    if (inorder.empty())
      return nullptr;

    int n = inorder.size();

    for (int i = 0; i < n; i++)
    {
      inMap[inorder[i]] = i;
    }
    pos = 0;

    return build(preorder, inorder, 0, n - 1);
  }

  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int inL, int inR)
  {
    if (inL > inR)
      return nullptr;

    TreeNode *root = new TreeNode(preorder[pos]);
    int mid = inMap[preorder[pos]];
    pos++;

    root->left = build(preorder, inorder, inL, mid - 1);
    root->right = build(preorder, inorder, mid + 1, inR);

    return root;
  }

private:
  unordered_map<int, int> inMap;
  int pos;
};

int main()
{
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  Solution *s = new Solution;
  s->buildTree(preorder, inorder);
  return 0;
}