#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Applicable scenario: the data contains a large number of duplicate elements, which results in fewer levels when expanded.
 */
class Solution
{
private:
  vector<vector<int>> ans;
  vector<pair<int, int>> freqs;
  vector<int> seq;

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    // Preprocess
    sort(candidates.begin(), candidates.end());
    for (int candidate : candidates)
    {
      if (freqs.empty() || freqs.back().first != candidate)
      {
        freqs.push_back({candidate, 1});
      }
      else
      {
        freqs.back().second++;
      }
    }

    backtracking(0, target);

    return ans;
  }

  void backtracking(int pos, int rest)
  {
    if (rest == 0)
    {
      ans.push_back(seq);
      return;
    }

    if (pos >= freqs.size() || rest < freqs[pos].first)
      return;

    // Skip the current number
    backtracking(pos + 1, rest);

    int num = freqs[pos].first;
    int freq = freqs[pos].second;

    // Key point: Incremental addition
    int most = min(rest / num, freq);
    for (int i = 1; i <= most; i++)
    {
      seq.push_back(num);
      backtracking(pos + 1, rest - i * num);
    }

    for (int i = 1; i <= most; i++)
      seq.pop_back();
  }
};

int main()
{
  vector<int> nums = {2, 5, 2, 1, 2};

  Solution *sol = new Solution;
  sol->combinationSum2(nums, 5);
  return 0;
}