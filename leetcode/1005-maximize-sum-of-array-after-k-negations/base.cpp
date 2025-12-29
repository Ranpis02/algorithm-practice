#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int largestSumAfterKNegations(vector<int> &nums, int k)
  {
    int n = nums.size();

    int maxSum = 0;
    sort(nums.begin(), nums.end());

    auto it = lower_bound(nums.begin(), nums.end(), 0);

    int bnd = it - nums.begin();

    int reversedBnd = min(bnd, k);

    int minAbs = INT_MAX;

    for (int i = 0; i < reversedBnd; i++)
    {
      minAbs = min(minAbs, abs(nums[i]));

      maxSum += -1 * nums[i];
    }

    for (int i = reversedBnd; i < n; i++)
    {
      minAbs = min(minAbs, abs(nums[i]));
      maxSum += nums[i];
    }

    if (k > bnd && (k - bnd) & 1)
    {
      maxSum -= 2 * minAbs;
    }

    return maxSum;
  }
};

int main()
{
  vector<int> nums = {-8, 3, -5, -3, -5, -2};

  Solution *sol = new Solution;

  sol->largestSumAfterKNegations(nums, 6);

  return 0;
}