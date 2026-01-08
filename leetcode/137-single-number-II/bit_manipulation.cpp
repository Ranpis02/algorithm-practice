#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int ans = 0;
    int n = nums.size();

    for (int i = 31; i >= 0; i--)
    {
      int cntOnes = 0;
      for (int j = 0; j < n; j++)
      {
        if (nums[j] & (1 << i))
          cntOnes++;
      }

      if (cntOnes % 3 == 1)
      {
        ans |= (1 << i);
      }
      // ans |= ((cntOnes % 3) << i);
      // ans |= (cntOnes % 3);
      // ans <<= 1;
    }

    return ans;
  }
};

int main()
{

  return 0;
}