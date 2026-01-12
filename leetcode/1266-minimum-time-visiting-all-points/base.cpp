#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points)
  {
    if (points.empty())
      return 0;

    int n = points.size();
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
      int dx = abs(points[i][0] - points[i - 1][0]);
      int dy = abs(points[i][1] - points[i - 1][1]);

      int min_val = min(dx, dy);

      ans += max(dy, dx) - min_val + min_val;
    }

    return ans;
  }
};

int main()
{
  return 0;
}