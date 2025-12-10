#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;
  vector<int> path;
  // unordered_map<int, int> exists;
  vector<char> visited;

public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    ans.clear();
    path.clear();
    visited.assign(42, 0);

    path.resize(nums.size());

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

    for (int num : nums)
    {
      int k = num + 20;
      if (visited[k])
        continue;

      visited[k] = 1;

      path[i] = num;
      backtracking(nums, i + 1);

      visited[k] = 0;
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