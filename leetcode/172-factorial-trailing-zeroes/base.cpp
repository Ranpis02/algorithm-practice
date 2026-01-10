#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int trailingZeroes(int n)
  {
    if (n == 0)
      return 0;

    int totalTwos = 0, totalFives = 0;
    for (int i = 1; i <= n; i++)
    {
      auto [twos, fives] = count(i);
      totalTwos += twos;
      totalFives += fives;
    }

    return min(totalTwos, totalFives);
  }

  pair<int, int> count(int x)
  {
    if (x == 0)
      return {0, 0};

    int twoCnt = 0, fiveCnt = 0;
    while (x != 1 && x % 2 == 0)
    {
      x /= 2;
      twoCnt++;
    }

    while (x != 1 && x % 5 == 0)
    {
      x /= 5;
      fiveCnt++;
    }

    return {twoCnt, fiveCnt};
  }
};

int main()
{

  return 0;
}