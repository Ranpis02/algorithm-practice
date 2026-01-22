#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minimumPairRemoval(vector<int> &nums)
  {
    int n = nums.size();

    while (nums.size() > 1)
    {
      if (check(nums))
      {
        break;
      }

      int minVal = INT_MAX;
      int idx = -1;

      for (int i = 0; i < nums.size() - 1; i++)
      {
        if (nums[i] + nums[i + 1] < minVal)
        {
          minVal = nums[i] + nums[i + 1];
          idx = i;
        }
      }

      nums.erase(nums.begin() + idx);
      nums[idx] = minVal;
    }

    return n - nums.size();
  }

  bool check(vector<int> &nums)
  {
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] < nums[i - 1])
        return false;
    }

    return true;
  }
};

int main()
{
  vector<int> nums = {2, 2, -1, 3, -2, 2, 1, 1, 1, 0, -1};

  Solution *sol = new Solution;

  sol->minimumPairRemoval(nums);

  return 0;
}