#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The calculation formula is: Water = min(H_{left max} - H_{right max}) -  H_{current}
 */
class Solution_TLM
{
public:
  int trap(vector<int> &height)
  {
    int ans = 0;

    for (int i = 0; i < height.size(); i++)
    {
      int leftMax = height[i];
      int rightMax = height[i];

      for (int j = i - 1; j >= 0; j--)
      {
        leftMax = max(height[j], leftMax);
      }

      if (leftMax <= height[i])
        continue;

      for (int j = i + 1; j < height.size(); j++)
      {
        rightMax = max(height[j], rightMax);
      }

      if (rightMax <= height[i])
        continue;

      int water = min(leftMax, rightMax) - height[i];
      water = water > 0 ? water : 0;

      ans += water;
    }

    return ans;
  }
};

int main()
{

  vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  // Solution *s = new Solution;
  // s->trap(nums);
  return 0;
}