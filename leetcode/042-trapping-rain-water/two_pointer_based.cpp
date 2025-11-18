#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    if (!height.size())
      return 0;

    int left = 0, right = height.size() - 1;

    int leftMax = 0, rightMax = 0;

    int ans = 0;
    // Process the side that has the lower maximum height —— the bottleneck side
    while (left < right)
    {

      if (height[left] < height[right])
      {
        // Left side is the bottleneck, deal with it
        leftMax = max(leftMax, height[left]);
        ans += (leftMax - height[left]);
        left++;
      }
      else
      {
        rightMax = max(rightMax, height[right]);
        ans += (rightMax - height[right]);
        right--;
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}