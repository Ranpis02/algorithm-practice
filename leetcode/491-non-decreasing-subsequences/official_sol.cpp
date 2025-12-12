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

    int used[202] = {0};
    for (int i = startIdx; i < nums.size(); i++)
    {
      // Purning 1: If the current number is strictly smaller than the last element, it violates the rule.
      if (!sub.empty() && nums[i] < sub.back())
        continue;

      // Purning 2: Check if the current value has already used in the current recursion level.
      if (used[nums[i] + 100] == 1)
        continue;

      used[nums[i] + 100] = 1;
      sub.push_back(nums[i]);
      backtracking(nums, i + 1);
      sub.pop_back();
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