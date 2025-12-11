#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;
  vector<int> sub;

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    ans.clear();
    sub.clear();

    ans.reserve(1 << nums.size());

    sort(nums.begin(), nums.end());
    backtracking(nums, 0);

    return ans;
  }

  void backtracking(const vector<int> &nums, int startIdx)
  {
    ans.push_back(sub);

    for (int i = startIdx; i < nums.size(); i++)
    {
      if (i > startIdx && nums[i] == nums[i - 1])
        continue;

      sub.push_back(nums[i]);
      backtracking(nums, i + 1);
      sub.pop_back();
    }
  }
};

int main()
{
  return 0;
}