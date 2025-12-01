#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * For example: [-2, 1, -3, 4, -1]
 *
 * 1  |      * (Peak: 1)           * (Peak: 4)
 * 0  |-----/--\------------------/--\-------
 *    |    /    \                /    \
 * -1 |   /      \              /      * (End)
 * -2 |  * (Start)\            /
 *    |            \          /
 * -4 |             * (Valley: -4)
 *
 */
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    // int sum = 0;
    int valley = 0;
    int ans = INT_MIN;
    int sum = 0;

    for (const auto &num : nums)
    {
      sum += num;
      ans = max(sum - valley, ans);
      valley = min(sum, valley);
    }

    return ans;
  }
};

int main()
{
  Solution *s = new Solution;

  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  s->maxSubArray(nums);
  return 0;
}