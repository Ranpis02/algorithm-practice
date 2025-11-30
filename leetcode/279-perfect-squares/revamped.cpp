#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numSquares(int n)
  {
    constexpr int INF = 0x3f3f3f3f;
    vector<int> dp(n + 1);

    dp[0] = 0;

    // for (int i = 1; i * i <= n; i++)
    // {
    //   dp[i] = i;

    //   for (int j = i * i; j <= n; j++)
    //   {
    //     dp[j] = min(dp[j - i * i], dp[j]);
    //   }
    // }

    for (int i = 1; i <= n; i++)
    {
      dp[i] = i;
      for (int j = 1; j * j <= i; j++)
      {
        dp[i] = min(dp[i], dp[i - j * j]);
      }
    }
    return dp[n];
  }
};

int main()
{

  return 0;
}