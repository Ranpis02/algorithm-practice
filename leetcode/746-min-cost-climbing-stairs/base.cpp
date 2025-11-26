#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();
    if (n <= 1)
      return 0;

    int *dp = new int[n + 1];
    dp[0] = dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
      dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }

    return dp[n];
  }
};

int main()
{
  return 0;
}