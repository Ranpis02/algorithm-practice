#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();

    int l = 0, r = m - 1;
    int k = -1;

    while (l <= r)
    {
      int mid = l + ((r - l) >> 1);

      if (matrix[mid][0] <= target)
      {
        l = mid + 1;
        k = mid;
      }
      else
      {
        r = mid - 1;
      }
    }

    if (k == -1)
      return false;

    // auto it = lower_bound(matrix[k].begin(), matrix[k].end(), target);
    // if (it != matrix[k].end() && ((*it) == target))
    // {
    //   return true;
    // }
    // else
    // {
    //   return false;
    // }

    return binary_search(matrix[k].begin(), matrix[k].end(), target);
  }
};

class Solution_2
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();

    auto row = upper_bound(matrix.begin(), matrix.end(), target, [](int target, const vector<int> &m)
                           { return target < m[0]; });

    if (row == matrix.begin())
      return false;

    row--;

    return binary_search(row->begin(), row->end(), target);
  }
};

int main()
{
  vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  Solution *sol = new Solution;
  sol->searchMatrix(nums, 3);

  return 0;
}