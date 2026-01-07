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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    if (postorder.empty())
      return nullptr;

    inMap.clear();
    int n = inorder.size();
    pos = n - 1;

    for (int i = 0; i < n; i++)
    {
      inMap[inorder[i]] = i;
    }

    return build(inorder, postorder, 0, n - 1);
  }

  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inL, int inR)
  {
    if (inL > inR)
      return nullptr;
    TreeNode *root = new TreeNode(postorder[pos]);

    int mid = inMap[postorder[pos]];
    pos--;

    root->right = build(inorder, postorder, mid + 1, inR);
    root->left = build(inorder, postorder, inL, mid - 1);

    return root;
  }

private:
  unordered_map<int, int> inMap;
  int pos;
};

int main()
{
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  Solution *s = new Solution;
  s->buildTree(inorder, postorder);
  return 0;
}