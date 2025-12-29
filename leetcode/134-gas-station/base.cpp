#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * gas: [5, 8, 2, 8]
 * cost: [6, 5, 6, 6]
 */
class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int n = gas.size();

    int start = 0;
    int totalSum = 0, crrSum = 0;
    for (int i = 0; i < n; i++)
    {
      int diff = gas[i] - cost[i];

      totalSum += diff;
      crrSum += diff;

      if (crrSum < 0)
      {
        start = i + 1;
        crrSum = 0;
      }
    }

    if (totalSum < 0)
      return -1;

    return start;
  }
};

int main()
{
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};

  Solution *sol = new Solution;
  int ans = sol->canCompleteCircuit(gas, cost);
  cout << ans << endl;

  return 0;
}