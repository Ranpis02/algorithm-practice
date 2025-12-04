#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;

public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> nums;

    backtracking(nums, k, n, 1);

    return ans;
  }

  void backtracking(vector<int> &nums, int k, int target, int startIdx)
  {
    if (nums.size() == k)
    {
      if (0 == target)
        ans.push_back(nums);

      return;
    }

    // Pruning 1: when i > (9 - (k - nums.size()) + 1), the remaining elements can't meet the requirement.
    for (int i = startIdx; i <= (9 - (k - nums.size()) + 1); i++)
    {
      // Pruning 2: If the current number exceeds the remaining target, stop early.
      if ((target - i) < 0)
        break;
      // target -= i;
      nums.push_back(i);

      backtracking(nums, k, target - i, i + 1);

      nums.pop_back();
      // target += i;
    }
  }
};

int main()
{

  return 0;
}