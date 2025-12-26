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
    int minStock = prices[0];
    int totalProfit = 0;

    for (int i = 1; i < n; i++)
    {
      if (prices[i] > minStock)
      {
        totalProfit += prices[i] - minStock;
        minStock = prices[i];
      }
      else
      {
        minStock = prices[i];
      }
    }

    return totalProfit;
  }
};

int main()
{

  return 0;
}