#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minPairSum(vector<int> &nums)
  {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int ans = INT_MAX;
    for (int i = 0; i < n / 2; i++)
    {
      ans = min(ans, nums[i] + nums[n - i - 1]);
    }

    return ans;
  }
};

int main()
{

  return 0;
}