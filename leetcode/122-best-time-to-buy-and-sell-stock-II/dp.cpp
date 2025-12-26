#include <iostream>
#include <vector>

using namespace std;

/**
 * - dp[i][0]: the profit when holding stock
 * - dp[i][1]: the profit when selling stock
 *
 * State Transition:
 * - dp[i][0] = max{dp[i - 1][0], dp[i - 1][1] - prices[i]}
 * - dp[i][1] = max{dp[i - 1][1], dp[i - 1][0] + prices[i]}
 */
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    if (prices.empty())
      return 0;

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; i++)
    {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return dp[n - 1][1];
  }
};

int main()
{

  return 0;
}