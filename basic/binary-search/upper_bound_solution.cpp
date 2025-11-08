#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Find the index of the first element greater than the given target.
 */
int greater_than_solution(const vector<int> &nums, int target)
{
  int l = 0, r = nums.size();

  while (l < r)
  {
    int mid = l + ((r - l) >> 1);
    if (nums[mid] <= target)
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
  vector<int> nums = {1, 3, 3, 5, 7};
  int res = greater_than_solution(nums, 3);

  cout << res << endl;

  return 0;
}