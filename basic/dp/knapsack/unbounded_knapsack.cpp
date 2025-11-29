#include <iostream>
#include <vector>

using namespace std;

/**
 * The core diference from the 0/1 Knapsack problem is that in the Unbounded Knapsack problem, each item is available in unlimited quantities.
 *
 * (1) DP Equation: dp[i][j] = max{max{dp[i - 1][j - k * w[i] + k * v[i]]}, dp[i - 1][j]} (1 <= k <= j / w[i])
 * *********************************************************************************************
 * => (2) dp[i][j] = max{max{dp[i - 1][j - k * w[i] - w[i]] + k * v[i] + v[i]}, d[i - 1][j]} (0 <= k <= j / w[i] - 1)
 * *********************************************************************************************
 * (3) dp[i][j] = max{dp[i - 1][j - k * w[i]]} (0 <= k <= j / w[i])
 * *********************************************************************************************
 * replace `j` with `j - w[i]`:
 * *********************************************************************************************
 * (4) dp[i][j - w[i]] = max{dp[i - 1][j - k * w[i] - w[i]] + k * v[i]} (0 <= k <= j / w[i] - 1)
 * *********************************************************************************************
 * By subsituting Equation (4) into (2), we obtain:
 * *********************************************************************************************
 * (5) dp[i][j] = max{dp[i][j - w[i]] + v[i], dp[i - 1]}
 *
 */
int unboundedKnapsack(const vector<int> &weights, const vector<int> &values, int capacity)
{
  int n = weights.size();
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

  // Explicitly declare
  for (int j = 0; j <= capacity; j++)
  {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    int w = weights[i - 1], v = values[i - 1];
    for (int j = 0; j <= capacity; j++)
    {
      if (j >= w)
      {
        dp[i][j] = max(dp[i][j - w] + v, dp[i - 1][j]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][capacity];
}

int unboundedKnapsackRolling(const vector<int> &weights, const vector<int> &values, int capacity)
{
  int n = weights.size();
  vector<int> dp(capacity + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    int w = weights[i - 1], v = values[i - 1];
    for (int j = w; j <= capacity; j++)
      dp[j] = max(dp[j - w] + v, dp[j]);

    return dp[capacity];
  }
}

int main()
{

  return 0;
}