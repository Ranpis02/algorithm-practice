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

    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
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