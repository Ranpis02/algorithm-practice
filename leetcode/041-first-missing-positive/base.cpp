#include <bits/stdc++.h>

using namespace std;

/**
 * In-place Hashing:
 * When the following conditions holds, we swap nums[i] and nums[nums[i]]:
 *
 * 1. nums[i] > 0;
 * 2. nums[i] <= n;
 * 3. nums[nums[i] - 1] != nums[i]
 */
class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
      {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (nums[i] != i + 1)
      {
        return i + 1;
      }
    }

    return n + 1;
  }
};

int main()
{

  return 0;
}