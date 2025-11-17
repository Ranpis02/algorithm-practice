#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> s(n + 1);

    for (int i = 1; i <= n; i++)
    {
      s[i] += nums[i - 1] + s[i - 1];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
      for (int j = i + 1; j <= n; j++)
      {
        if ((s[j] - s[i]) == k)
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