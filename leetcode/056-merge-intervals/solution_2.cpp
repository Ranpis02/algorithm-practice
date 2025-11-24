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

    vector<vector<int>> ans;
    ans.push_back({intervals[0][0], intervals[0][1]});

    for (int i = 1; i < intervals.size(); i++)
    {
      if (ans.back()[1] >= intervals[i][0])
      {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
      else
      {
        ans.push_back({intervals[i][0], intervals[i][1]});
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
  return 0;
}