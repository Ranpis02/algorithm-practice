#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;
  vector<int> sub;

public:
  vector<vector<int>> findSubsequences(vector<int> &nums)
  {
    ans.clear();
    sub.clear();

    backtracking(nums, 0);

    return ans;
  }

  void backtracking(const vector<int> &nums, int startIdx)
  {
    if (sub.size() >= 2)
    {
      ans.push_back(sub);
    }

    for (int i = startIdx; i < nums.size(); i++)
    {

      int t = INT_MIN;
      for (int j = i - 1; j >= startIdx; j--)
      {
        if (nums[i] == nums[j])
        {
          t = nums[j];
          break;
        }
      }

      if (i > startIdx && nums[i] == t)
        continue;

      if (sub.empty() || nums[i] >= sub.back())
      {
        sub.push_back(nums[i]);
        backtracking(nums, i + 1);
        sub.pop_back();
      }
    }
  }
};

int main()
{
  vector<int> nums = {1, 2, 1};
  Solution *sol = new Solution;
  auto res = sol->findSubsequences(nums);
  for (auto vec : res)
  {
    for (auto num : vec)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}