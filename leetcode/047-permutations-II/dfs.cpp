#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  vector<vector<int>> ans;
  vector<int> path;
  vector<bool> visited;

public:
  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    ans.clear();
    path.clear();

    int n = nums.size();
    path.resize(n);
    visited.assign(n, false);

    sort(nums.begin(), nums.end());
    backtracking(nums, 0);

    return ans;
  }

  void backtracking(vector<int> &nums, int start)
  {
    if (start == nums.size())
    {
      ans.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      // The role of `visited[i - 1]`: prevent deplicate branches at the same recursion level.
      if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
        continue;

      visited[i] = true;
      path[start] = nums[i];
      backtracking(nums, start + 1);
      visited[i] = false;
    }
  }
};

int main()
{
  vector<int> nums = {1, 1, 2};
  Solution *sol = new Solution;
  sol->permuteUnique(nums);

  return 0;
}