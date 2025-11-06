#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Merge the arrays and then find the median
 */
class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    int i = 0, j = 0, k = 0;
    int s1 = nums1.size(), s2 = nums2.size();

    vector<int> nums3(s1 + s2);
    while (i < s1 && j < s2)
    {
      if (nums1[i] <= nums2[j])
        nums3[k++] = nums1[i++];
      else
        nums3[k++] = nums2[j++];
    }

    while (i < s1)
      nums3[k++] = nums1[i++];
    while (j < s2)
      nums3[k++] = nums2[j++];

    if (k & 1)
    {
      return nums3[k / 2];
    }
    else
    {
      return (nums3[k / 2 - 1] + nums3[k / 2]) / 2.0;
    }
  }
};

int main()
{
  vector<int> nums1 = {1, 3};
  vector<int> nums2 = {2};

  Solution *s = new Solution;

  s->findMedianSortedArrays(nums1, nums2);

  return 0;
}