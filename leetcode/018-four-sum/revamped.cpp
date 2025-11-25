#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size();

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      // If the sum of the four smallest numbers exceeds the target, then break out of the loop.
      if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
        break;

      // If the sum of current number and the three largest numbers is less than the target, then skip to next iteration.
      if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
        continue;

      for (int j = i + 1; j < n - 2; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
          break;
        if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
          continue;

        int l = j + 1, r = n - 1;

        while (l < r)
        {
          long long gap = (long long)target - nums[i] - nums[j];
          long long t = nums[l] + nums[r];
          if (gap == t)
          {
            ans.push_back({nums[i], nums[j], nums[l], nums[r]});

            while (l < r && nums[l] == nums[l + 1])
              l++;
            while (l < r && nums[r] == nums[r - 1])
              r--;

            l++;
            r--;
          }
          else if (gap > t)
          {
            l++;
          }
          else
          {
            r--;
          }
        }
      }
    }

    return ans;
  }
};

int main()
{
  vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
  int target = 0;

  Solution *s = new Solution;
  s->fourSum(nums, target);

  return 0;
}