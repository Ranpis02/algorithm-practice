#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int repeatedNTimes(vector<int> &nums)
  {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
      for (int gap = 1; gap <= 3; gap++)
      {
        if (i + gap < n && nums[i] == nums[i + gap])
        {
          return nums[i];
        }
      }
    }

    return -1;
  }
};

int main()
{

  return 0;
}