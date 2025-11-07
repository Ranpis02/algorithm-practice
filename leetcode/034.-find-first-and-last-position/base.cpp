#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
      int mid = l + ((r - l) >> 1);

      if (nums[mid] == target)
      {
        int l_bound = mid;
        int r_bound = mid;
        while (l_bound >= l)
        {
          if ((l_bound - 1) >= l && nums[l_bound - 1] == target)
            l_bound--;
          else
            break;
        }

        while (r_bound <= r)
        {
          if ((r_bound + 1) <= r && nums[r_bound + 1] == target)
            r_bound++;
          else
            break;
        }

        return vector<int>{l_bound, r_bound};
      }
      else if (nums[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return vector<int>{-1, -1};
  }
};

int main()
{
  return 0;
}