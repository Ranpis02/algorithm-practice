#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    // Since the matrix is square, so width is also n.
    int n = matrix.size(), m = matrix[0].size();

    int left = matrix[0][0], right = matrix[n - 1][m - 1];

    while (left < right)
    {
      int mid = left + ((right - left) >> 1);

      if (lessCount(matrix, mid) >= k)
      {
        right = mid;
      }
      else
      {
        left = mid + 1;
      }
    }

    return left;
  }

  int lessCount(vector<vector<int>> &matrix, int mid)
  {
    int n = matrix.size(), m = matrix[0].size();

    int cnt = 0;
    int i = n - 1, j = 0;

    while (i >= 0 && j < m)
    {
      if (matrix[i][j] <= mid)
      {
        cnt += i + 1;
        j++;
      }
      else
      {
        i--;
      }
    }

    return cnt;
  }
};

int main()
{

  return 0;
}