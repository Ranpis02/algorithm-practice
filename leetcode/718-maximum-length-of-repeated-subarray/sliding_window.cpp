#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size(), n = nums2.size();

    int ans = 0;
    // Maintain the nums1, slide the nums2
    for (int i = 0; i < m; i++)
    {
      int len = min(m - i, n);

      int maxLen = maxLength(nums1, nums2, i, 0, len);
      ans = max(ans, maxLen);
    }

    for (int i = 0; i < n; i++)
    {
      int len = min(m, n - i);
      int maxLen = maxLength(nums1, nums2, 0, i, len);
      ans = max(ans, maxLen);
    }

    return ans;
  }

  int maxLength(const vector<int> &nums1, const vector<int> &nums2, int start1, int start2, int len)
  {
    int maxLen = 0;
    int k = 0;
    for (int i = 0; i < len; i++)
    {
      if (nums1[start1 + i] == nums2[start2 + i])
      {
        k++;
        maxLen = max(maxLen, k);
      }
      else
      {
        k = 0;
      }
    }

    return maxLen;
  }
};

int main()
{
  vector<int> nums1 = {1, 2, 3, 2, 1};
  vector<int> nums2 = {3, 2, 1, 4, 7};

  Solution *s = new Solution;
  s->findLength(nums1, nums2);
  return 0;
}