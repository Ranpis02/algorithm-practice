#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Solution
{
public:
  int fib(int n)
  {
    if (n == 0)
      return 0;

    if (n == 1)
      return 1;

    int prevp = 0, prev = 1;

    int cur;
    for (int i = 2; i <= n; i++)
    {
      cur = prevp + prev;

      prevp = prev;
      prev = cur;
    }

    return cur;
  }
};

int main()
{
  Solution *s = new Solution;
  s->fib(3);
  return 0;
}