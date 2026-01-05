#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>> &matrix)
  {
    int row = matrix.size(), col = matrix[0].size();

    int cnt = 0;
    int minAbs = INT_MAX;
    long long ans = 0;

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (matrix[i][j] < 0)
        {
          cnt++;
        }

        ans += abs(matrix[i][j]);
        minAbs = min(minAbs, abs(matrix[i][j]));
      }
    }

    if (cnt & 1)
    {
      ans -= 2 * minAbs;
    }

    return ans;
  }
};

int main()
{

  return 0;
}