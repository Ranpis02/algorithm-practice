#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 1. Scan from left to right, maintaining the maximum value, to find the rightmost index of unsorted element;
 *
 * 2. Conversely, scan from right to left, maintaining the minimum value, to determine the leftmost boundary.
 *
 */
class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    if (is_sorted(nums.begin(), nums.end()))
    {
      return 0;
    }

    int left = nums.size() - 1, right = 0;

    int maxValue = nums[left], minValue = nums[right];

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] < minValue)
        right = i;
      minValue = max(nums[i], minValue);

      if (nums[n - i - 1] > maxValue)
        left = n - i - 1;
      maxValue = min(nums[n - i - 1], maxValue);
    }

    return right - left + 1;
  }
};

int main()
{

  return 0;
}