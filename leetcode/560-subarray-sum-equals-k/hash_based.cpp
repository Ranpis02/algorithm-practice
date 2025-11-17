#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int ans = 0;
    unordered_map<int, int> mp;

    mp[0] = 1;

    int acc = 0;
    for (int num : nums)
    {
      acc += num;

      if (mp.count(acc - k))
      {
        ans += mp[acc - k];
      }

      mp[acc]++;
    }

    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 1, 1};
  int k = 2;

  Solution *s = new Solution;
  s->subarraySum(nums, k);

  return 0;
}