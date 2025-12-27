#include <iostream>
#include <vector>

using namespace std;

/**
 * State Machine:
 * - hold[i]: hold the stock
 * - sold[i]: sell the stock
 * - rest[i]: don't hold the stock and didn't sell today.
 *
 * State Transition:
 *
 *
 */
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    if (prices.empty())
      return 0;

    int n = prices.size();

    int hold = -prices[0];
    int sold = 0;
    int rest = 0;

    for (int i = 1; i < n; i++)
    {
      int prevHold = hold;
      int prevSold = sold;
      int preRest = rest;

      hold = max(prevHold, preRest - prices[i]);

      sold = prevHold + prices[i];

      rest = max(preRest, prevSold);
    }

    return max(sold, rest);
  }
};

int main()
{

  return 0;
}