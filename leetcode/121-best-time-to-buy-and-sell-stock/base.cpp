#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    if (prices.empty())
      return 0;

    int n = prices.size();

    int maxProfit = 0;
    // int maxState = prices[0];
    int minState = prices[0];

    for (int i = 1; i < n; i++)
    {
      // if (prices[i] > maxState)
      // {
      //   profit += (prices[i] - maxState);
      //   maxState = prices[i];
      // }

      if ((prices[i] - minState) > maxProfit)
      {
        // maxState = prices[i];
        maxProfit = prices[i] - minState;
      }

      if (prices[i] < minState)
      {
        minState = prices[i];
      }
    }

    return maxProfit;
  }
};

int main()
{
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  Solution *sol = new Solution;
  sol->maxProfit(prices);

  return 0;
}