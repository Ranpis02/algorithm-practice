#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0)
        break;

      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int l = i + 1, r = n - 1;

      while (l < r)
      {
        int t = nums[i] + nums[l] + nums[r];

        if (t == 0)
        {
          ans.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l + 1] == nums[l])
            l++;
          while (l < r && nums[r - 1] == nums[r])
            r--;
          l++;
          r--;
        }
        else if (t < 0)
        {
          l++;
        }
        else
        {
          r--;
        }
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}