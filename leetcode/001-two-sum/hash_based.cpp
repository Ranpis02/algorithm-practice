#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    // `.first`: The value of element, `second`: The index of element.
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
      auto it = mp.find(target - nums[i]);
      if (it != mp.end())
      {
        return {(*it).second, i};
      }
      mp.insert({nums[i], i});
    }

    return {};
  }
};

int main()
{

  return 0;
}