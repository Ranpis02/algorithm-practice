#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();

    if (n <= 2)
      return n;

    int fast = 2, slow = 2;

    while (fast < n)
    {
      // The newly added element won't result in three identical numbers in the current list.
      if (nums[slow - 2] != nums[fast])
      {
        nums[slow] = nums[fast];
        slow++;
      }

      fast++;
    }

    return slow;
  }
};

int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 3};

  Solution *sol = new Solution;
  sol->removeDuplicates(nums);

  return 0;
}