#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    constexpr int INT_F = 0x3f3f3f3f;
    vector<int> dp(amount + 1, INT_F);

    dp[0] = 0;
    for (int coin : coins)
    {
      for (int i = coin; i <= amount; i++)
      {
        dp[i] = min(dp[i - coin] + 1, dp[i]);
      }
    }

    return (dp[amount] >= INT_F ? -1 : dp[amount]);
  }
};

int main()
{
  return 0;
}