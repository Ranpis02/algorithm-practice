#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <unordered_set>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());

    vector<int> combination;
    backtracking(candidates, target, 0, combination, 0);

    // sort(ans.begin(), ans.end());
    // ans.erase(unique(ans.begin(), ans.end()), ans.end());

    return ans;
  }

  void backtracking(const vector<int> &candidates, const int target, int sum, vector<int> &combination, int startIdx)
  {
    if (sum == target)
    {
      ans.push_back(combination);
      return;
    }

    for (int i = startIdx; i < candidates.size(); i++)
    {
      int candidate = candidates[i];
      if ((sum + candidate) > target)
        break;

      if (i > startIdx && candidates[i] == candidates[i - 1])
        continue;

      combination.push_back(candidate);
      backtracking(candidates, target, sum + candidate, combination, i + 1);
      combination.pop_back();
    }
  }
};

int main()
{
  vector<int> nums = {2, 5, 2, 1, 2};

  Solution *sol = new Solution;
  sol->combinationSum2(nums, 5);
  return 0;
}