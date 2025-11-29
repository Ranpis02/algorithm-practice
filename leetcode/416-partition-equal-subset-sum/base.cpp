#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int total = 0;
    for (int num : nums)
    {
      total += num;
    }

    if (total & 1)
      return false;

    int c = total / 2;
    vector<bool> dp(c + 1, false);

    dp[0] = true;
    for (int num : nums)
    {
      for (int j = c; j >= num; j--)
      {
        dp[j] = dp[j - num] || dp[j];
      }

      // Pruning
      if (dp[c])
        return true;
    }

    return dp[c];
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 5};

  Solution *s = new Solution;
  s->canPartition(nums);

  return 0;
}