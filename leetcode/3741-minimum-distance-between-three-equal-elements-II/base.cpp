#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int minimumDistance(vector<int> &nums)
  {
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < nums.size(); i++)
    {
      mp[nums[i]].push_back(i);
    }

    int minDistance = INT_MAX;
    for (auto &[_, v] : mp)
    {
      if (v.size() >= 3)
      {
        for (int i = 2; i < v.size(); i++)
        {
          minDistance = min(2 * (v[i] - v[i - 2]), minDistance);
        }
      }
    }

    return minDistance == INT_MAX ? -1 : minDistance;
  }
};

int main()
{
  vector<int> nums = {1, 2, 1, 1, 3};

  Solution *s = new Solution;
  s->minimumDistance(nums);

  return 0;
}