#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int row = matrix.size(), col = matrix[0].size();

    vector<vector<int>> dp(row, vector<int>(col, 0));

    int ans = 0;
    for (int i = 0; i < row; i++)
    {
      if (matrix[i][0] == '1')
      {
        ans = 1;
        dp[i][0] = 1;
      }
    }

    for (int i = 0; i < col; i++)
    {
      if (matrix[0][i] == '1')
      {
        ans = 1;
        dp[0][i] = 1;
      }
    }

    for (int i = 1; i < row; i++)
    {
      for (int j = 1; j < col; j++)
      {
        if (matrix[i][j] == '1')
        {
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
          ans = max(dp[i][j] * dp[i][j], ans);
        }
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