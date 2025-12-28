#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    int n = nums.size();

    int preDiff = 0, curDiff = 0;
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
      curDiff = nums[i] - nums[i - 1];

      if (preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0)
      {
        preDiff = curDiff;
        ans++;
      }
    }

    return ans;
  }
};

int main()
{
  
  return 0;
}