#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> permuteUnique(vector<int> &nums)
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
  return 0;
}