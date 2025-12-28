#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int rob(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    int n = nums.size();
    if (n == 1)
      return nums[0];

    int val1 = robHelp(nums, 0, n - 1);
    int val2 = robHelp(nums, 1, n);

    return max(val1, val2);
  }

  int robHelp(vector<int> &nums, int start, int end)
  {
    int take = nums[start];
    int skip = 0;

    for (int i = start + 1; i < end; i++)
    {
      int preTake = take;
      int preSkip = skip;

      skip = max(preSkip, preTake);
      take = preSkip + nums[i];
    }

    return max(skip, take);
  }
};

int main()
{

  return 0;
}