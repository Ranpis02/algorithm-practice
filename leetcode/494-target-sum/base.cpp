#include <iostream>
#include <vector>

using namespace std;

/**
 * Partition the `nums` into two subsets, one for positive numbers and the other for negative numbers.
 *
 * x - y = target, x = sum - y => y = (sum - target) / 2
 * Transition Formula: dp[j] = dp[j] + dp[j - nums[i]]
 * Note: dp[j] represents the number of ways to form sum `j`.
 */
class Solution
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size();
    int sum = 0;

    for (int num : nums)
    {
      sum += num;
    }

    int c;
    int x = sum - target;

    if (x < 0 || x & 1)
      return 0;
    else
      c = (sum - target) / 2;

    vector<int> dp(c + 1, 0);
    dp[0] = 1;
    for (int num : nums)
    {
      for (int j = c; j >= num; j--)
      {
        dp[j] += dp[j - num];
      }
    }

    return dp[c];
  }
};

int main()
{
  vector<int> nums = {2, 107, 109, 113, 127, 131, 137, 3, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 47, 53};

  Solution *s = new Solution;
  s->findTargetSumWays(nums, 1000);
  return 0;
}