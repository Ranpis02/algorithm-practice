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

    backtracking(nums, 0);

    return ans;
  }

  void backtracking(vector<int> &nums, int i)
  {
    if (i == nums.size())
    {
      ans.push_back(path);

      return;
    }

    backtracking(nums, i + 1);

    path.push_back(nums[i]);
    backtracking(nums, i + 1);
    path.pop_back();
  }
};

int main()
{
  return 0;
}