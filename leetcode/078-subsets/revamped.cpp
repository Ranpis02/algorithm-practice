#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;
  vector<int> path;

public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    ans.clear();
    path.clear();
    int n = nums.size();
    ans.reserve(1 << n);

    backtracking(nums, 0);

    return ans;
  }

  void backtracking(const vector<int> &nums, int startIndex)
  {
    ans.push_back(path);

    for (int i = startIndex; i < nums.size(); i++)
    {
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
};

int main()
{
  vector<int> nums = {1, 2, 3};
  Solution *sol = new Solution;
  sol->subsets(nums);

  return 0;
}