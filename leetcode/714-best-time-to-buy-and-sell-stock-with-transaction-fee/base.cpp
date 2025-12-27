#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
    if (prices.empty())
      return 0;

    int n = prices.size();

    int buy = -prices[0];
    int sell = 0;

    for (int i = 1; i < n; i++)
    {
      int preBuy = buy;
      int preSell = sell;

      // Tip: Safe to use updated 'buy' as same-day trading is suboptimal due to fees.
      buy = max(preBuy, preSell - prices[i]);
      sell = max(preSell, preBuy + prices[i] - fee);
    }

    return sell;
  }
};

int main()
{

  return 0;
}