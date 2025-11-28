#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int integerBreak(int n)
  {
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;

    if (n % 3 == 1)
    {
      return fastExp(3, (n - 4) / 3) * 4;
    }
    else if (n % 3 == 2)
    {
      return fastExp(3, (n - 2) / 3) * 2;
    }

    return fastExp(3, n / 3);
  }

  long long fastExp(long long a, long long n)
  {
    long long ans = 1;

    while (n)
    {
      if (n & 1)
        ans *= a;
      a *= a;
      n >>= 1;
    }

    return ans;
  }
};

int main()
{
  Solution *s = new Solution;
  return 0;
}