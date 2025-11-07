#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
      int mid = l + ((r - l) >> 1);

      if (nums[mid] == target)
        return mid;
      
      // Caution: the following comparsion must use `<=` instead of `<`. For example, [3, 3, 1, 2]
      if (nums[l] <= nums[mid])
      {
        if (target < nums[mid] && target >= nums[l])
        {
          r = mid - 1;
        }
        else
        {
          l = mid + 1;
        }
      }
      else
      {
        if (target <= nums[r] && target > nums[mid])
        {
          l = mid + 1;
        }
        else
        {
          r = mid - 1;
        }
      }
    }

    return -1;
  }
};

int main()
{
  vector<int> nums = {3, 1};

  Solution *s = new Solution;
  cout << s->search(nums, 1);
  return 0;
}