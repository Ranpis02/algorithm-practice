#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    int n = points.size();

    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); });

    int ans = 1;
    int end = points[0][1];

    for (int i = 1; i < n; i++)
    {
      int s = points[i][0];
      int t = points[i][1];

      if (s > end)
      {
        ans++;
        end = t;
      }

      end = min(t, end);
    }

    return ans;
  }
};

class Solution_2
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    int n = points.size();

    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    int ans = 1;

    int pos = points[0][1];
    for (int i = 1; i < n; i++)
    {
      if (points[i][0] > pos)
      {
        pos = points[i][1];
        ans++;
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}