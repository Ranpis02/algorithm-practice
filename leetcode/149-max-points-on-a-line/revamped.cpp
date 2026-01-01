#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  struct Slope
  {
    int x, y;

    bool operator==(const Slope &other) const
    {
      return (x == other.x) && (y == other.y);
    }
  };

  struct SlopeHash
  {
    size_t operator()(const Slope &other) const
    {
      return hash<int>()(other.x) ^ hash<int>()(other.y << 1);
    }
  };

  int maxPoints(vector<vector<int>> &points)
  {
    int n = points.size();

    if (n <= 2)
      return n;

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      unordered_map<Slope, int, SlopeHash> slope_map;
      int duplicate = 1;

      for (int j = i + 1; j < n; j++)
      {
        int dx = points[i][0] - points[j][0];
        int dy = points[i][1] - points[j][1];

        if (dx == 0 && dy == 0)
          duplicate++;

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

        if (dy == 0)
        {
          dx = abs(dx);
        }

        Slope s{dx, dy};
        slope_map[s]++;
      }

      for (auto &p : slope_map)
      {
        ans = max(ans, p.second + duplicate);
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

  return 0;
}