#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>

using namespace std;

class Solution_TLE
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        for (int k = j + 1; k < nums.size(); k++)
        {
          if (nums[i] + nums[j] + nums[k] == 0)
            ans.push_back({nums[i], nums[j], nums[k]});
        }
      }
    }

    // ans.erase(unique(ans.begin(), ans.end()), ans.end());
    set<vector<int>> st(ans.begin(), ans.end());

    return vector<vector<int>>(st.begin(), st.end());
  }
};

int main()
{

  vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  // Solution *s = new Solution;
  // auto res = s->threeSum(nums);

  return 0;
}