#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    do
    {
      ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));

    return ans;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3};

  Solution *sol = new Solution;
  sol->permute(nums);
  return 0;
}