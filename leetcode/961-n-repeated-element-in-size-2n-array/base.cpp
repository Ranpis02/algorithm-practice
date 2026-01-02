#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int repeatedNTimes(vector<int> &nums)
  {
    int n = nums.size();

    unordered_map<int, int> mp;

    for (auto num : nums)
    {
      mp[num]++;
      if (mp[num] == n / 2)
      {
        return num;
      }
    }

    return -1;
  }
};

int main()
{

  return 0;
}