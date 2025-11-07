#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    auto range = equal_range(nums.begin(), nums.end(), target);

    if (range.first == range.second)
    {
      return vector<int>{-1, -1};
    }
    else
    {
      // Caution: the expression `range.first - nums.begin()` return a value of type `ptrdiff_t`
      int first = range.first - nums.begin();
      int second = range.second - nums.begin() - 1;
      return vector<int>{first, second};
    }
  }
};

int main()
{
  return 0;
}