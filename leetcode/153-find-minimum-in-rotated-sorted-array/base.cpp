#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size();

    int left = 0, right = n - 1;

    while (left < right)
    {
      int mid = left + ((right - left) >> 1);

      if (nums[mid] > nums[right])
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
      }
    }

    return nums[left];
  }
};

int main()
{
  vector<int> nums = {266, 267, 268, 269, 271, 278, 282, 292, 293, 298, 6, 9, 15, 19, 21, 26, 33, 35, 37, 38, 39, 46, 49, 54, 65, 71, 74, 77, 79, 82, 83, 88, 92, 93, 94, 97, 104, 108, 114, 115, 117, 122, 123, 127, 128, 129, 134, 137, 141, 142, 144, 147, 150, 154, 160, 163, 166, 169, 172, 173, 177, 180, 183, 184, 188, 198, 203, 208, 210, 214, 218, 220, 223, 224, 233, 236, 241, 243, 253, 256, 257, 262, 263};
  Solution *sol = new Solution;
  sol->findMin(nums);

  return 0;
}