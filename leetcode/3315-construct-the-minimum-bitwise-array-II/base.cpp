#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> minBitwiseArray(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] != 2)
      {
        int t = nums[i];

        int len = 0;

        while (t & 1)
        {
          t >>= 1;
          len++;
        }

        nums[i] = nums[i] ^ (1 << (len - 1));
      }
      else
      {
        nums[i] = -1;
      }
    }

    return nums;
  }
};

int main()
{

  return 0;
}