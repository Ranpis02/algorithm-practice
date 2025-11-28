#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Q1: Why use `j * dp[i - j]` instead of `dp[i] * dp[i - j]`?
 * The definition of dp[i] implies x must be split into at least two integers.
 * By using `j` directly, we allow one of the factors to remain as a row, unsplit integer, which maximizes the product
 *
 * Q2: Why loop only up to 1 / 2?
 * Due to commutative property of addition, splitting `i` to `j + (i - j)` is effectively the same as `(i - j) + j`. Besides, to find the optimal solution, iterating throug the smaller whalf is sufficient, as splitting small numbers results in a smaller product.
 *
 */
class Solution
{
public:
  int integerBreak(int n)
  {
    vector<int> dp(n + 1, 0);

    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
      for (int j = 1; j <= i / 2; j++)
      {
        dp[i] = max({j * dp[i - j], j * (i - j), dp[i]});
      }
    }
    return dp[n];
  }
};

int main()
{
  Solution *s = new Solution;
  s->integerBreak(10);
  return 0;
}