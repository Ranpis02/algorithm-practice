#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Perform two binary searcher to find:
 * 1. the index of the first element equal to the target
 * 2. the index of the first element greater than the target
 */
class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int leftIdx = binarySearch(nums, target, true);

    int rightIdx = binarySearch(nums, target, false);

    if (leftIdx == rightIdx)
      return vector<int>{-1, -1};
    else
      return vector<int>{leftIdx, rightIdx - 1};
  }

private:
  /**
   * @param nums The array to search in.
   * @param target The target value to search for.
   * @param lower Control the mode of binary search:
   *              - true, find first >= target;
   *              - false, find first > target.
   *
   * @return The index of the first element that meets the condition.
   */
  int binarySearch(const vector<int> &nums, int target, bool lower)
  {
    int l = 0, r = nums.size();

    while (l < r)
    {
      int m = l + ((r - l) >> 1);
      if ((!lower && nums[m] <= target) || (lower && nums[m] < target))
      {
        l = m + 1;
      }
      else
      {
        r = m;
      }
    }

    return l;
  }
};

int main()
{
  return 0;
}