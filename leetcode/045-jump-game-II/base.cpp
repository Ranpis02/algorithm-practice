#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();

    int pos = 0;
    int ans = 0;
    while (true)
    {
      int maxLen = 0;
      int nextPos = pos;
      if (pos == n - 1)
        break;

      if (pos + nums[pos] >= n - 1)
      {
        ans++;
        break;
      }

      for (int i = 1; i <= nums[pos]; i++)
      {
        if ((pos + i) < n && i + nums[pos + i] > maxLen)
        {
          maxLen = i + nums[pos + i];
          nextPos = pos + i;
        }
      }
      pos = nextPos;

      ans++;
    }

    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 2, 1, 1, 1};
  Solution *sol = new Solution;
  sol->jump(nums);

  return 0;
}