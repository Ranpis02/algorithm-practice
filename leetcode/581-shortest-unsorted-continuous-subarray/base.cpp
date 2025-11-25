#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    if (is_sorted(nums.begin(), nums.end()))
    {
      return 0;
    }

    vector<int> numsCopy(nums);

    sort(numsCopy.begin(), numsCopy.end());

    int start = -1, end = -1;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != numsCopy[i])
      {
        start = i;
        break;
      }
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (nums[i] != numsCopy[i])
      {
        end = i;
        break;
      }
    }

    return (end - start + 1);
  }
};

int main()
{

  return 0;
}