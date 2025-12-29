#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();

    // vector<int> steps(n);
    int maxPos = 0;
    int end = 0;

    int level = 0;

    for (int i = 0; i < n - 1; i++)
    {
      // steps[level + 1] = max(steps[level + 1], i + nums[i]);
      maxPos = max(maxPos, i + nums[i]);

      // if (i == steps[level])
      if (i == end)
      {
        level++;
        end = maxPos;
      }
    }

    return level;
  }
};

int main()
{
  vector<int> nums = {2, 3, 1, 2, 4, 2};
  Solution *sol = new Solution;
  sol->jump(nums);

  return 0;
}