#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    if (!root)
      return "#";

    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    istringstream iss(data);

    string item;
    queue<string> q;
    while (getline(iss, item, ','))
    {
      q.push(item);
    }

    return buildTree(q);
  }

private:
  TreeNode *buildTree(queue<string> &q)
  {
    TreeNode *root;

    if (q.empty())
      return nullptr;

    string val = q.front();
    q.pop();

    if (val == "#")
      return nullptr;

    root = new TreeNode(stoi(val));

    root->left = buildTree(q);
    root->right = buildTree(q);

    return root;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};

  TreeNode *root = createTree(nums);
  Codec *codec = new Codec;
  string str = codec->serialize(root);
  cout << str << endl;

  return 0;
}