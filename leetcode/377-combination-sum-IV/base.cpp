#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int combinationSum4(vector<int> &nums, int target)
  {
    int n = nums.size();
    // unsigned == unsigned int
    vector<unsigned> dp(target + 1, 0);

    dp[0] = 1;
    // Iterate over knapsack capacity, then items, to get permutations.
    for (int i = 0; i <= target; i++)
    {
      for (int num : nums)
      {
        if (i >= num)
          dp[i] += dp[i - num];
      }
    }

    return dp[target];
  }
};

int main()
{
  return 0;
}