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
    int prev = nums[0];
    int maxVal = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      prev = max(prev + nums[i], nums[i]);
      maxVal = max(prev, maxVal);
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