#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
  vector<vector<int>> ans;
  vector<int> path;

public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    ans.clear();
    path.clear();

    path.resize(nums.size());
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

    for (int i = start; i < nums.size(); i++)
    {
      swap(nums[i], nums[start]);
      path[start] = nums[start];
      backtracking(nums, start + 1);
      swap(nums[i], nums[start]);
    }
  }
};

int main()
{
  vector<int> nums = {1, 2, 3};

  Solution *sol = new Solution;
  sol->permute(nums);
  return 0;
}