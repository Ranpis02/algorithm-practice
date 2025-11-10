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

/**
 * Create a binary tree in level-order manner.
 * In the input array, use -1 represent null nodes.
 */
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

/**
 *  Preorder Traversal: root -> left -> right
 */
void preorder(TreeNode *root)
{
  if (root)
  {
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

/**
 * Inorder Traversal: left -> root -> right
 */
void inorder(TreeNode *root)
{
  if (root)
  {
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
  }
}

/**
 * Postorder Traversal: left -> right -> root
 */
void postorder(TreeNode *root)
{
  if (root)
  {
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
  }
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};

  TreeNode *root = createTree(nums);

  cout << "preorder: ";
  preorder(root);
  cout << endl;

  cout << "inorder: ";
  inorder(root);
  cout << endl;

  cout << "postorder: ";
  postorder(root);
  cout << endl;
  return 0;
}