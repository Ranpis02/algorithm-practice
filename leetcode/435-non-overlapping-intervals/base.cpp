#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    int n = intervals.size();

    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]); });

    int ans = 0;

    int end = intervals[0][1];

    for (int i = 1; i < n; i++)
    {
      int s = intervals[i][0];
      int t = intervals[i][1];

      if (s >= end)
      {
        end = t;
      }
      else
      {
        ans++;
        end = min(end, t);
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}