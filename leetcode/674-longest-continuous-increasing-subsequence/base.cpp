#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int findLengthOfLCIS(vector<int> &nums)
  {
    int maxLen = 1;
    int len = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] > nums[i - 1])
        len++;
      else
      {
        len = 1;
      }
      maxLen = max(maxLen, len);
    }

    return maxLen;
  }
};
int main()
{
  return 0;
}