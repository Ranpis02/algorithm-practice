#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    // int slow = 1, fast = 1;
    int cnt = 1;
    int j = 1;

    for (int i = 1; i < n; i++)
    {
      if (nums[i] == nums[i - 1])
        cnt++;
      else
        cnt = 1;

      if (cnt <= 2)
      {
        nums[j] = nums[i];
        j++;
      }
    }

    return j;
  }
};

int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
  Solution *sol = new Solution;
  sol->removeDuplicates(nums);

  return 0;
}