#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_map<int, bool> mp;

    for (int i = 0; i < nums.size(); i++)
    {
      mp[nums[i]] = false;
    }

    int maxLen = 0;
    for (auto val : mp)
    {
      if (val.second)
        continue;

      int start = val.first;
      while (mp.count(start - 1))
      {
        start -= 1;
      }

      int len = 0;
      while (mp.count(start))
      {
        len++;
        mp[start] = true;

        start++;
      }

      if (len > maxLen)
        maxLen = len;
    }

    return maxLen;
  }
};

int main()
{
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  Solution *s = new Solution;
  s->longestConsecutive(nums);

  return 0;
}