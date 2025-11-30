#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numSquares(int n)
  {
    vector<int> nums;
    for (int i = 1; i * i <= n; i++)
    {
      nums.push_back(i * i);
    }

    constexpr int INF = 0x3f3f3f3f;
    vector<int> dp(n + 1, INF);

    dp[0] = 0;
    for (int num : nums)
    {
      for (int i = num; i <= n; i++)
      {
        dp[i] = min(dp[i - num] + 1, dp[i]);
      }
    }

    return dp[n];
  }
};

int main()
{

  return 0;
}