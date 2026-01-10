#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int row = matrix.size(), col = matrix[0].size();

    vector<int> dp(col, 0);

    int ans = 0;

    for (int i = 0; i < col; i++)
    {
      if (matrix[0][i] == '1')
      {
        ans = 1;
        dp[i] = max(ans, 1);
      }
    }

    for (int i = 1; i < row; i++)
    {
      int diag = dp[0];

      if (matrix[i][0] == '1')
      {
        dp[0] = 1;
        ans = max(ans, 1);
      }
      else
      {
        dp[0] = 0;
      }

      for (int j = 1; j < col; j++)
      {
        int tmp = dp[j];

        if (matrix[i][j] == '1')
        {
          dp[j] = min({dp[j], dp[j - 1], diag}) + 1;
          ans = max(dp[j] * dp[j], ans);
        }
        else
        {
          dp[j] = 0;
        }
        diag = tmp;
      }
    }

    return ans;
  }
};

int main()
{
  vector<vector<char>> matrix = {{'0', '1'}, {'1', '0'}};

  Solution *sol = new Solution;
  sol->maximalSquare(matrix);

  return 0;
}