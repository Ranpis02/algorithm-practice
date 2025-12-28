#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    int n = nums.size();

    // vector<int> up(n), down(n);

    // up[0] = down[0] = 1;

    int up = 1, down = 1;
    for (int i = 1; i < n; i++)
    {

      if (nums[i - 1] < nums[i])
      {
        up = down + 1;
      }
      else if (nums[i - 1] > nums[i])
      {
        down = up + 1;
      }
      // if (nums[i - 1] < nums[i])
      // {
      //   up[i] = down[i - 1] + 1;
      //   down[i] = down[i - 1];
      // }
      // else if (nums[i - 1] > nums[i])
      // {
      //   up[i] = up[i - 1];
      //   down[i] = up[i - 1] + 1;
      // }
      // else
      // {
      //   up[i] = up[i - 1];
      //   down[i] = down[i - 1];
      // }
    }

    return max(up, down);
    // return max(up[n - 1], down[n - 1]);
  }
};

int main()
{

  return 0;
}