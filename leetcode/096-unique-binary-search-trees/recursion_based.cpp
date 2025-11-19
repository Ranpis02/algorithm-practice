#include <iostream>

using namespace std;

/**
 * Core idea:
 * 1. Select a root from 1 to n
 * 2. Decomposition: if `i` is the root, the `i - 1` smaller nodes from the left subtree(giving G( i -1)), an the `n - i` larger nodes from right subtree(giving G(n - i))
 * 3. Formula: G(n) = \sum_{G(i - 1)G(n - i)}
 */
class Solution
{
public:
  int numTrees(int n)
  {
    if (n == 1 || n == 0)
      return 1;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
      ans += numTrees(i - 1) * numTrees(n - i);
    }
    return ans;
  }
};

int main()
{

  return 0;
}