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

    for (int i = 0; i < n; i++)
    {
      inMap[inorder[i]] = i;
    }

    return build(inorder, postorder, 0, n - 1, n - 1);
  }

  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int inL, int inR, int pos)
  {
    if (inL > inR || pos >= postorder.size() || pos < 0)
      return nullptr;

    if (inL == inR)
      return new TreeNode(inorder[inL]);

    TreeNode *root = new TreeNode(postorder[pos]);

    int mid = inMap[postorder[pos]];

    int numL = mid - inL;
    int numR = inR - mid;

    root->left = build(inorder, postorder, inL, mid - 1, pos - numR - 1);
    root->right = build(inorder, postorder, mid + 1, inR, pos - 1);

    return root;
  }

private:
  unordered_map<int, int> inMap;
};

int main()
{
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  Solution *s = new Solution;
  s->buildTree(preorder, inorder);
  return 0;
}