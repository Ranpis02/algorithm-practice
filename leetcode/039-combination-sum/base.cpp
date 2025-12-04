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
    backtracking(candidates, target, 0, combination);

    return ans;
  }

  void backtracking(const vector<int> &candidates, int target, int sum, vector<int> &combination)
  {
    if (sum >= target)
    {
      if (sum == target)
        ans.push_back(combination);

      return;
    }

    // for (int candidate : candidates)
    // {
    //   if (!combination.empty() && candidate < combination.back())
    //     continue;

    //   if ((sum + candidate) > target)
    //     break;

    //   combination.push_back(candidate);
    //   backtracking(candidates, target, sum + candidate, combination);
    //   combination.pop_back();
    // }
    int minVal = combination.empty() ? INT_MIN : combination.back();
    auto it = lower_bound(candidates.begin(), candidates.end(), minVal);

    for (auto i = it; i != candidates.end(); i++)
    {
      if (sum + (*i) > target)
        break;

      combination.push_back(*i);
      backtracking(candidates, target, sum + (*i), combination);
      combination.pop_back();
    }
  }
};
int main()
{
  return 0;
}