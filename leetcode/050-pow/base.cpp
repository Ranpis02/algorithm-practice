#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  double myPow(double x, int n)
  {
    if (n == 0)
      return 1;

    if (x == 0)
      return 0;

    double ans = 1;
    long long N = n;

    if (N < 0)
    {
      x = 1 / x;
      N = -N;
    }

    while (N)
    {
      if (N & 1)
        ans *= x;

      x *= x;
      N >>= 1;
    }

    return ans;
  }
};

int main()
{
  double x = 2;
  int n = 10;

  Solution *sol = new Solution;
  sol->myPow(x, n);
  return 0;
}