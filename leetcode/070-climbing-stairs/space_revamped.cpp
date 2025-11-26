#include <iostream>

using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {
    if (n == 1 || n == 2)
      return n;

    int dp[2];
    dp[0] = 1, dp[1] = 2;

    int ans;

    for (int i = 3; i <= n; i++)
    {
      ans = dp[0] + dp[1];

      dp[0] = dp[1];
      dp[1] = ans;
    }

    return ans;
  }
};

int main()
{

  return 0;
}