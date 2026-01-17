#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  long long largestSquareArea(vector<vector<int>> &bottomLeft, vector<vector<int>> &topRight)
  {
    int n = bottomLeft.size();

    int len = 0;
    for (int i = 0; i < n; i++)
    {
      const auto &bottomCor1 = bottomLeft[i];
      const auto &topCor1 = topRight[i];

      for (int j = i + 1; j < n; j++)
      {
        const auto &bottomCor2 = bottomLeft[j];
        const auto &topCor2 = topRight[j];

        int bx = max(bottomCor1[0], bottomCor2[0]);
        int by = max(bottomCor1[1], bottomCor2[1]);

        int tx = min(topCor1[0], topCor2[0]);
        int ty = min(topCor1[1], topCor2[1]);

        len = max(len, min(max(tx - bx, 0), max(ty - by, 0)));
      }
    }

    return (long long)len * len;
  }
};

int main()
{

  return 0;
}