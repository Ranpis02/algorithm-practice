#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size(), n = matrix[0].size();

    int low = 0, high = m * n - 1;

    while (low <= high)
    {
      int mid = low + ((high - low) >> 1);

      int ele = matrix[mid / n][mid % n];
      if (ele == target)
      {
        return true;
      }
      else if (ele > target)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return false;
  }
};

int main()
{
  vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  Solution *sol = new Solution;
  sol->searchMatrix(nums, 3);

  return 0;
}