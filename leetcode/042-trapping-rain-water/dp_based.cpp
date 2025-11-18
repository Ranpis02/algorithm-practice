#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();

    vector<int> rightMax(n), leftMax(n);

    int leftMaximum = 0, rightMaximum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      leftMaximum = max(height[i], leftMaximum);
      leftMax[i] = leftMaximum;
      rightMaximum = max(height[n - 1 - i], rightMaximum);
      rightMax[n - 1 - i] = rightMaximum;
    }

    for (int i = 0; i < n; i++)
    {
      int water = min(leftMax[i], rightMax[i]) - height[i];
      water = water > 0 ? water : 0;

      ans += water;
    }

    return ans;
  }
};
int main()
{

  vector<int> nums = {4, 2, 0, 3, 2, 5};

  Solution *s = new Solution;
  int res = s->trap(nums);
  return 0;
}