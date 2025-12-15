#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Instead of calculating the total score for each starting room i, we can calculate how mant starting room contribute to the score at room j.
 *
 * prefix[i] = damage[i] + prefix[i - 1], prefix[0] = 0.
 *
 * HP - (P[j] - P[i - 1]) >= requirement[j]
 * =>
 * P[i - 1] >= requirement[j] + P[j] - HP.
 */
class Solution
{
public:
  long long totalScore(int hp, vector<int> &damage, vector<int> &requirement)
  {
    int n = damage.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
      prefix[i + 1] = damage[i] + prefix[i];
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
      int threadshold = prefix[i] + requirement[i - 1] - hp;

      auto it = lower_bound(prefix.begin(), prefix.begin() + i, threadshold);

      if (it != (prefix.begin() + i))
      {
        ans += (prefix.begin() + i - it);
      }
    }

    return ans;
  }
};

int main()
{
  int hp = 11;
  vector<int> damage = {3, 6, 7};
  vector<int> req = {4, 2, 5};

  Solution *sol = new Solution;
  int res = sol->totalScore(hp, damage, req);
  return 0;
}