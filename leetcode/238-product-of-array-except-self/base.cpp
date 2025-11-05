#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Caution: This solution uses division, which voliates the requirement.
 */
class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int total = 1;
    vector<int> res;

    vector<int> zeroIndices;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
        total *= nums[i];
      else
        zeroIndices.push_back(i);
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0 && zeroIndices.size() != 0)
        res.push_back(0);
      else if (nums[i] != 0 && zeroIndices.size() == 0)
        res.push_back(total / nums[i]);
      else if (nums[i] == 0 && zeroIndices.size() > 1)
        res.push_back(0);
      else if (nums[i] == 0 && zeroIndices.size() == 1)
        res.push_back(total);
    }

    return res;
  }
};

int main()
{

  return 0;
}