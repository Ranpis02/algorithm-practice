#include <iostream>
#include <vector>

using namespace std;

/**
 * Try to split the stones into two groups of equal weight to minimize the remaining weight
 */
class Solution
{
public:
  int lastStoneWeightII(vector<int> &stones)
  {
    int n = stones.size();

    int totalWeight = 0;
    for (int stone : stones)
    {
      totalWeight += stone;
    }

    int c = totalWeight / 2;
    vector<int> dp(c + 1, 0);

    for (int stone : stones)
    {
      for (int j = c; j >= stone; j--)
      {
        dp[j] = max(dp[j], dp[j - stone] + stone);
      }
    }

    return (totalWeight - dp[c] * 2);
  }
};

int main()
{

  return 0;
}