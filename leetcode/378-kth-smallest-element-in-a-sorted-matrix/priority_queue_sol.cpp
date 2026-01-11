#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    int n = matrix.size();

    priority_queue<Node> pq;

    for (int i = 0; i < n; i++)
    {
      pq.push({matrix[0][i], 0, i});
    }

    for (int i = 0; i < k - 1 && !pq.empty(); i++)
    {
      auto node = pq.top();
      pq.pop();

      int x = node.x;
      int y = node.y;
      if (x + 1 < n)
      {
        pq.push({matrix[x + 1][y], x + 1, y});
      }
    }

    return pq.empty() ? -1 : pq.top().val;
  }

private:
  struct Node
  {
    int val;
    int x, y;

    bool operator<(const Node &other) const
    {
      return val > other.val;
    }
  };
};

int main()
{
  vector<vector<int>> nums = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};

  Solution *sol = new Solution;
  sol->kthSmallest(nums, 8);

  return 0;
}