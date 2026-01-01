#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxPoints(vector<vector<int>> &points)
  {
    int n = points.size();

    if (n <= 2)
      return n;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      unordered_map<string, int> slope_map;
      auto s = points[i];

      for (int j = i + 1; j < n; j++)
      {
        auto t = points[j];
        int dx = s[0] - t[0];
        int dy = s[1] - t[1];

        int common = gcd(dx, dy);

        dx /= common;
        dy /= common;

        if (dx < 0)
        {
          dx = -dx;
          dy = -dy;
        }
        else if (dx == 0)
        {
          dy = abs(dy);
        }

        string key = to_string(dy) + "_" + to_string(dx);
        slope_map[key]++;
      }

      for (auto &p : slope_map)
      {
        ans = max(ans, p.second + 1);
      }
    }

    return ans;
  }

  int gcd(int a, int b)
  {
    return b == 0 ? a : gcd(b, a % b);
  }
};

int main()
{
  vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};

  Solution *sol = new Solution;
  sol->maxPoints(points);

  return 0;
}