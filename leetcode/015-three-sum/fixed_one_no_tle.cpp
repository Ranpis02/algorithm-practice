#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

class Solution_TLE
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {

    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
      mp[nums[i]].push_back(i);

    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0)
        break;
      for (int j = i + 1; j < n; j++)
      {
        int gap = 0 - nums[i] - nums[j];
        if (mp.count(gap))
        {
          auto candidate = mp[gap];

          for (auto v : candidate)
          {
            if (v != i && v != j && v > j)
            {
              ans.push_back({nums[i], nums[j], nums[v]});
              break;
            }
          }
        }
      }
    }

    set<vector<int>> st(ans.begin(), ans.end());

    return vector<vector<int>>(st.begin(), st.end());
  }
};

int main()
{

  return 0;
}