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

    int *dp = new int[2];
    dp[0] = dp[1] = 0;

    int ans;

    for (int i = 2; i <= n; i++)
    {
      ans = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
      dp[0] = dp[1];
      dp[1] = ans;
    }

    delete[] dp;

    return ans;
  }
};

int main()
{
  return 0;
}