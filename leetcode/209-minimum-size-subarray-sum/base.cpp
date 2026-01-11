#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int ans = INT_MAX;

    int n = nums.size();
    int acc = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
      acc += nums[i];

      while (acc >= target)
      {
        if (acc >= target)
          ans = min(ans, i - j + 1);

        acc -= nums[j++];
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 11;

  Solution *sol = new Solution;
  sol->minSubArrayLen(target, nums);

  return 0;
}