#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    int n = nums.size();

    int minDp = nums[0], maxDp = nums[0];
    int minVal = nums[0], maxVal = nums[0], totalVal = nums[0];
    bool isAllNeg = true;
    for (int i = 1; i < n; i++)
    {
      minDp = min(minDp + nums[i], nums[i]);
      minVal = min(minVal, minDp);

      maxDp = max(maxDp + nums[i], nums[i]);
      maxVal = max(maxVal, maxDp);

      totalVal += nums[i];

      if (nums[i] > 0)
        isAllNeg = false;
    }

    return isAllNeg ? maxVal : max(maxVal, totalVal - minVal);
  }
};

int main()
{

  return 0;
}