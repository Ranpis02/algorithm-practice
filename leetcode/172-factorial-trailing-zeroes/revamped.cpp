#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int trailingZeroes(int n)
  {
    if (n == 0)
      return 0;

    int cnt = 0;
    while (n > 0)
    {
      n /= 5;
      cnt += n;
    }

    return cnt;
  }
};

int main()
{

  return 0;
}