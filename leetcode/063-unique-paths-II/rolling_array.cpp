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

    for (int i = 0; i < col && obstacleGrid[0][i] == 0; i++)
    {
      dp[i] = 1;
    }

    for (int i = 0; i < col; i++)
    {
      cout << dp[i] << " ";
    }
    cout << endl;
    bool flag = true;
    for (int i = 1; i < row; i++)
    {
      if (!obstacleGrid[i - 1][0] && !obstacleGrid[i][0] && flag)
      {
        dp[0] = 1;
      }
      else
      {
        flag = false;
        dp[0] = 0;
      }
      cout << dp[0] << " ";
      for (int j = 1; j < col; j++)
      {
        if (!obstacleGrid[i][j])
          dp[j] += dp[j - 1];
        else
        {
          dp[j] = 0;
        }
        cout << dp[j] << " ";
      }
      cout << endl;
    }

    return dp[col - 1];
  }
};

int main()
{
  vector<vector<int>> nums = {{1}, {0}};
  Solution *s = new Solution;
  s->uniquePathsWithObstacles(nums);

  return 0;
}