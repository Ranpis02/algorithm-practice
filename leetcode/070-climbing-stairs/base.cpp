#include <iostream>

using namespace std;

/**
 * Analyze two situations in the last time:
 * 1. current position is `n - 1`, then you can take 1 step to reach the `n`th step.
 * 2. current position is `n - 2`, then you can take 2 steps to reach the `n`th step.
 *
 * In conclusion,  the recurrence formula is : f(n) = f(n - 1) + f(n - 2)
 */
class Solution
{
public:
  int climbStairs(int n)
  {
    if (n == 1 || n == 2)
      return n;
    int *dp = new int[n + 1];

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
  }
};

int main()
{

  return 0;
}