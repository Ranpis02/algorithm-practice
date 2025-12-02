#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * This question can be viewed as a variant of the LCS problem.
 */
class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    int m = s.size(), n = t.size();
    if (m > n)
      return false;

    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
      int prev = 0;
      for (int j = 1; j <= m; j++)
      {
        int tmp = dp[j];
        if (t[i - 1] == s[j - 1])
          dp[j] = prev + 1;
        else
          dp[j] = max(dp[j], dp[j - 1]);
        prev = tmp;
      }
    }

    return dp[m] == m;
  }
};

int main()
{
  return 0;
}