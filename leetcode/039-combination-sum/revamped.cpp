#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<int> combination;
    backtracking(candidates, target, 0, combination, 0);

    return ans;
  }

  void backtracking(const vector<int> &candidates, int target, int sum, vector<int> &combination, int startIndex)
  {
    // if (sum >= target)
    // {
    if (sum == target)
    {
      ans.push_back(combination);

      return;
    }
    // }

    for (int i = startIndex; i < candidates.size(); i++)
    {
      int val = candidates[i];
      if ((sum + val) > target)
        break;

      combination.push_back(val);
      backtracking(candidates, target, sum + val, combination, i);
      combination.pop_back();
    }
  }
};

int main()
{
  return 0;
}