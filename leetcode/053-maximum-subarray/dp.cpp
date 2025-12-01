#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Transition equation: dp[i] = max(nums[i] + dp[i - 1], nums[i])
 * dp[i]: represents the maximum sum of the subarray ending with at index i.
 */
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n);

    dp[0] = nums[0];

    int maxVal = dp[0];
    for (int i = 1; i < n; i++)
    {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      maxVal = max(dp[i], maxVal);
    }

    return maxVal;
  }
};

int main()
{
  Solution *s = new Solution;

  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  s->maxSubArray(nums);
  return 0;
}