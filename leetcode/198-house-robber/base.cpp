#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int n = nums.size();

    // vector<vector<int>> dp(n, vector<int>(2));

    // dp[0][0] = 0;
    // dp[0][1] = nums[0];
    int skip = 0;
    int take = nums[0];

    for (int i = 1; i < n; i++)
    {
      int preSkip = skip;
      int preTake = take;
      skip = max(preSkip, preTake);
      take = preSkip + nums[i];
      // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      // dp[i][1] = dp[i - 1][0] + nums[i];
    }

    return max(skip, take);
    // return max(dp[n - 1][0], dp[n - 1][1]);
  }
};

int main()
{

  return 0;
}