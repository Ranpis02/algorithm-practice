#include <iostream>
#include <vector>

using namespace std;

/**
 * - dp[i][0]: no transaction yet
 * - dp[i][1]: the state after the first buy
 * - dp[i][2]: the state after the first sell
 * - dp[i][3]: the state after the second buy
 * - dp[i][4]: the state after the second sell
 *
 * State transition:
 * dp[i][0] = dp[i - 1][0] = 0
 * dp[i][1] = max{ dp[i - 1][0], dp[i - 1][0] - prices[i] }
 * dp[i][2] = max{ dp[i - 1][2], dp[i - 1][1] + prices[i] }
 * dp[i][3] = max{ dp[i - 1][3], dp[i - 1][2] - prices[i] }
 * dp[i][4] = max{ dp[i - 1][4], dp[i - 1][3] + prices[i] }
 *
 */
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    if (prices.empty())
      return 0;

    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(4));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    dp[0][2] = -prices[0];
    dp[0][3] = 0;

    for (int i = 1; i < n; i++)
    {
      dp[i][0] = max(dp[i - 1][0], -prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);

      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
    }

    return dp[n - 1][3];
  }
};

int main()
{

  vector<int> nums = {2, 4, 1};

  Solution *sol = new Solution;
  sol->maxProfit(nums);

  return 0;
}