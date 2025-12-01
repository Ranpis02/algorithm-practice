#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int findLengthOfLCIS(vector<int> &nums)
  {
    int n = nums.size();

    int startIdx = 0;
    int maxLen = 1;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] <= nums[i - 1])
        startIdx = i;
      maxLen = max(i - startIdx + 1, maxLen);
    }

    return maxLen;
  }
};
int main()
{
  return 0;
}