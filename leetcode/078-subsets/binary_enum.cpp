#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> ans;
    int n = nums.size();
    ans.reserve(n);
    int total = (1 << n);

    for (int i = 0; i < total; i++)
    {
      // int t = i;
      // int pos = 0;
      // vector<int> path;
      // while (t)
      // {
      //   if (t & 1)
      //   {
      //     path.push_back(nums[pos]);
      //   }

      //   t >>= 1;
      //   pos++;
      vector<int> sub;
      for (int j = 0; j < n; j++)
      {
        if ((i >> j) & 1)
        {
          sub.push_back(nums[j]);
        }
      }
      ans.push_back(sub);
    }
    return ans;
  }
};

int main()
{
  return 0;
}