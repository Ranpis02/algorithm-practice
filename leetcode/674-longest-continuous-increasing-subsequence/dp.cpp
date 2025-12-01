#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int findLengthOfLCIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n, 1);

    int maxLen = 1;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] > nums[i - 1])
        dp[i] = max(dp[i], dp[i - 1] + 1);

      maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
  }
};
int main()
{
  return 0;
}