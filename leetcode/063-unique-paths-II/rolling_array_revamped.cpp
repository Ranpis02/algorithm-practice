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

    vector<int> dp(col, 0);

    dp[0] = 1;

    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        if (obstacleGrid[i][j] == 1)
          dp[j] = 0;
        else
        {
          // Trick: For the first column, if we don't intervene, it will naturally carries over the value from the previous row.
          if (j > 0)
            dp[j] += dp[j - 1];
        }
      }
    }

    return dp[col - 1];
  }
};

int main()
{
  vector<vector<int>> nums = {{0, 0}, {1, 1}, {0, 0}};
  Solution *s = new Solution;
  s->uniquePathsWithObstacles(nums);

  return 0;
}