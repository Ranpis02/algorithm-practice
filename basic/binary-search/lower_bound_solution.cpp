#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Find the index of fist element greater than or equal to the given target.
 */
int lower_bound_solution(const vector<int> &nums, int target)
{
  // Caution: the right index is `nums.size()` instead of `nums.size() - 1`
  int l = 0, r = nums.size();

  while (l < r)
  {
    int mid = l + ((r - l) >> 1);

    if (nums[mid] < target)
    {
      l = mid + 1;
    }
    else
    {
      r = mid;
    }
  }

  return l;
}

int main()
{
  vector<int> nums = {1, 2};

  int res = lower_bound_solution(nums, 5);

  cout << res << endl;
  return 0;
}