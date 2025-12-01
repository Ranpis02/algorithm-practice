#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * dp[i]: represents the length of the longest strictly increasing subsequence ending at the current element.
 */
class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n, 1);

    int maxVal = 1;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[j] < nums[i])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      maxVal = max(maxVal, dp[i]);
    }

    return maxVal;
  }
};

int main()
{
  return 0;
}