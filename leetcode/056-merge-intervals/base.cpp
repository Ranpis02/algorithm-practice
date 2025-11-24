#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    if (intervals.empty())
      return {};

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    int maxReach = intervals[0][1];
    vector<int> tmp = {intervals[0][0], -1};

    intervals.push_back({INT_MAX, INT_MAX});
    vector<vector<int>> ans;

    for (auto interval : intervals)
    {
      if (maxReach >= interval[0])
        maxReach = max(maxReach, interval[1]);
      else
      {
        tmp[1] = maxReach;
        ans.push_back(tmp);

        tmp[0] = interval[0];
        maxReach = interval[1];
      }
    }

    return ans;
  }
};

void print(const vector<vector<int>> &vec)
{
  for (auto ve : vec)
  {
    for (auto v : ve)
    {
      cout << v << " ";
    }
    cout << endl;
  }
}
int main()
{

  vector<vector<int>> nums = {{1, 3},
                              {2, 6},
                              {8, 10},
                              {15, 18}};
  Solution *s = new Solution;

  vector<vector<int>> ans = s->merge(nums);

  print(ans);
  return 0;
}