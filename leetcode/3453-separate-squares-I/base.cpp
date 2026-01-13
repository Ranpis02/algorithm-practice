#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  double separateSquares(vector<vector<int>> &squares)
  {
    double low = 1e9, high = 0;
    double totalArea = 0;
    for (auto &square : squares)
    {
      double y = square[1];
      double len = square[2];
      totalArea += len * len;
      low = min(low, y);
      high = max(high, y + len);
    }

    double target = totalArea / 2.0;

    for (int i = 0; i < 70; i++)
    {
      double mid = low + (high - low) / 2.0;
      double crrArea = 0;

      for (auto &square : squares)
      {
        if (square[1] > mid)
          continue;

        double y = square[1];
        double len = square[2];
        double h = min(y + len, mid) - y;

        crrArea += h * len;
      }

      if (crrArea >= target)
      {
        high = mid;
      }
      else
      {
        low = mid;
      }
    }

    return high;
  }

private:
  static constexpr double eps = 1e5;
};

int main()
{

  return 0;
}