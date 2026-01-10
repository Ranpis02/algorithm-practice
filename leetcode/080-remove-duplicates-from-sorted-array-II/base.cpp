#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    // int cnt = 0;
    // for (int i = 2; i < n; i++)
    // {
    //   if (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
    //     cnt++;
    // }

    int idx = 2;
    while (idx < nums.size())
    {
      if (nums[idx] == nums[idx - 2])
      {
        nums.erase(nums.begin() + idx);
      }
      else
      {
        idx++;
      }
    }

    return nums.size();
  }
};

int main()
{

  return 0;
}