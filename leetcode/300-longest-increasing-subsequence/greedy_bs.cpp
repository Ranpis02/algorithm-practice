#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    vector<int> tail{nums[0]};

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] > tail.back())
        tail.push_back(nums[i]);
      else
      {
        auto it = lower_bound(tail.begin(), tail.end(), nums[i]);
        *it = nums[i];
      }
    }

    return tail.size();
  }
};

int main()
{
  return 0;
}