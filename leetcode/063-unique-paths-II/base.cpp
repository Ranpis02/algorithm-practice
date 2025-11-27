#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int row = obstacleGrid.size(), col = obstacleGrid[0].size();

    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < row && obstacleGrid[i][0] == 0; i++)
    {
      dp[i][0] = 1;
    }

    for (int i = 0; i < col && obstacleGrid[0][i] == 0; i++)
    {
      dp[0][i] = 1;
    }

    for (int i = 1; i < row; i++)
    {
      for (int j = 1; j < col; j++)
      {
        if (!obstacleGrid[i][j])
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[row - 1][col - 1];
  }
};

int main()
{
  vector<vector<int>> nums = {{0, 1}, {1, 0}};
  Solution *s = new Solution;
  s->uniquePathsWithObstacles(nums);

  return 0;
}