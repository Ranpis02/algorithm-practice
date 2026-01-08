#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    unordered_map<int, int> mp;

    for (int num : nums)
    {
      mp[num]++;
    }

    for (auto &[key, val] : mp)
    {
      if (val == 1)
        return key;
    }

    return -1;
  }
};

int main()
{

  return 0;
}