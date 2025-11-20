#include <iostream>
#include <vector>
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

TreeNode *create(vector<int> &nums)
{
  if (nums.empty() || nums[0] == -1)
    return nullptr;

  int n = nums.size();
  vector<TreeNode *> nodes(n);

  for (int i = 0; i < n; i++)
  {
    if (nums[i] == -1)
      continue;
    nodes[i] = new TreeNode(nums[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (!nodes[i])
      continue;

    int leftIdx = 2 * i + 1;
    int rightIdx = 2 * i + 2;

    if (leftIdx < n)
      nodes[i]->left = nodes[leftIdx];
    if (rightIdx < n)
      nodes[i]->right = nodes[rightIdx];
  }

  return nodes[0];
}

class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    if (!root)
      return {};

    queue<TreeNode *> q;
    vector<vector<int>> ans;

    q.push(root);

    while (!q.empty())
    {
      vector<int> tmp;
      TreeNode *tail = q.back();

      while (true)
      {
        TreeNode *head = q.front();
        if (!head)
          continue;
        tmp.push_back(head->val);

        if (head->left)
          q.push(head->left);
        if (head->right)
          q.push(head->right);

        if (q.front() == tail)
        {
          q.pop();
          break;
        }
        q.pop();
      };

      ans.push_back(tmp);
    }

    return ans;
  }
};

int main()
{
  vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = create(nums);

  Solution *s = new Solution;
  s->levelOrder(root);
  return 0;
}