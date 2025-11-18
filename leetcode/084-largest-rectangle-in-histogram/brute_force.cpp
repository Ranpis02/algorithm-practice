#include <iostream>
#include <vector>

using namespace std;

/**
 * Fix a height and find the maximum width it can extend.
 */
class Solution_TLE
{
public:
  int largestRectangleArea(vector<int> &heights)
  {
    int maximum = 0;
    for (int i = 0; i < heights.size(); i++)
    {
      int height = heights[i];

      int width = 1;

      for (int j = i - 1; j >= 0; j--)
      {
        if (heights[j] >= height)
          width++;
        else
          break;
      }

      for (int j = i + 1; j < heights.size(); j++)
      {
        if (heights[j] >= height)
          width++;
        else
          break;
      }

      maximum = max(width * height, maximum);
    }

    return maximum;
  }
};

int main()
{
  vector<int> nums = {2, 1, 5, 6, 2, 3};

  return 0;
}