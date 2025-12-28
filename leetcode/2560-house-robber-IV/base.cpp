#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
  int minCapability(vector<int> &nums, int k)
  {
    // int left = *min_element(nums.begin(), nums.end());
    // int right = *max_element(nums.begin(), nums.end());

    int n = nums.size();
    int left = INT_MAX, right = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      left = min(left, nums[i]);
      right = max(right, nums[i]);
    }

    int ans = right;
    while (left <= right)
    {
      int mid = left + ((right - left) >> 1);

      if (check(nums, mid, k))
      {
        right = mid - 1;
        ans = mid;
      }
      else
      {
        left = mid + 1;
      }
    }

    return ans;
  }

  bool check(vector<int> &nums, int ability, int k)
  {
    int acc = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (ability >= nums[i])
      {
        acc++;
        if (acc >= k)
          return true;
        i++;
      }
    }

    return false;
  }
};

int main()
{

  return 0;
}