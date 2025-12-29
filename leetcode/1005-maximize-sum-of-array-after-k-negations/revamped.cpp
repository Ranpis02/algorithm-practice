#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  static bool cmp(int a, int b)
  {
    return abs(a) > abs(b);
  }

  int largestSumAfterKNegations(vector<int> &nums, int k)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end(), cmp);

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] < 0 && k > 0)
      {
        ans -= nums[i];
        k--;
      }
      else
      {
        ans += nums[i];
      }
    }

    if (k & 1)
      ans -= nums[n - 1];
    else
      ans += nums[n - 1];

    return ans;
  }
};

int main()
{

  return 0;
}