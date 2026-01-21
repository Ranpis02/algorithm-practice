#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> minBitwiseArray(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] != 2)
      {
        int t = nums[i];

        int len = 0;
        while (t)
        {
          t >>= 1;
          len++;

          if (t % 2 == 0)
            break;
        }

        t <<= 1;
        for (int j = 0; j < len - 1; j++)
          t = t << 1 | 1;

        nums[i] = t;
      }
      else
      {
        nums[i] = -1;
      }
    }

    return nums;
  }
};

int main()
{
  vector<int> nums = {2, 3, 5, 7};

  Solution *sol = new Solution;
  sol->minBitwiseArray(nums);

  return 0;
}