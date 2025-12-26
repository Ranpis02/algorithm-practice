#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    if (prices.empty() || k == 0)
      return 0;

    int n = prices.size();

    vector<int> buy(k + 1, -prices[0]);
    vector<int> sell(k + 1, 0);

    // Optimize: if k >= n / 2, the promblems reduce to the case of unlimited transactions.
    if (k >= n / 2)
    {
      int profit = 0;
      for (int i = 1; i < n; i++)
      {
        if (prices[i] > prices[i - 1])
          profit += prices[i] - prices[i - 1];
      }

      return profit;
    }

    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j <= k; j++)
      {
        buy[j] = max(buy[j], sell[j - 1] - prices[i]);
        sell[j] = max(sell[j], buy[j] + prices[i]);
      }
    }

    return sell[k];
  }
};

int main()
{

  return 0;
}