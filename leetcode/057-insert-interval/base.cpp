#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    vector<vector<int>> ans;

    int new_s = newInterval[0], new_t = newInterval[1];
    int n = intervals.size();

    int i = 0;
    while (i < n)
    {
      int s = intervals[i][0], t = intervals[i][1];

      if (s > new_t)
      {
        break;
      }

      if (t < new_s)
      {
        ans.push_back(intervals[i]);
      }
      else
      {
        new_s = min(s, new_s);
        new_t = max(t, new_t);
      }

      i++;
    }

    ans.push_back({new_s, new_t});

    for (int j = i; j < n; j++)
    {
      ans.push_back(intervals[j]);
    }

    return ans;
  }
};

int main()
{

  return 0;
}