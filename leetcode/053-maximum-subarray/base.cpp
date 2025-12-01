#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution_TLE
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> s(n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      s[i] = sum;
    }

    int maxVal = s[0];

    for (int i = 1; i < n; i++)
    {
      maxVal = max(maxVal, s[i]);

      for (int j = 0; j < i; j++)
      {
        maxVal = max(s[i] - s[j], maxVal);
      }
    }

    return maxVal;
  }
};

int main()
{
  // Solution *s = new Solution;

  // vector<int> nums = {5, 4, -1, 7, 8};
  // s->maxSubArray(nums);
  return 0;
}