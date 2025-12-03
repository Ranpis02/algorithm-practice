#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Transition Equation:
 * d[i][j]: represents the number of distinct subsequences of the first `j` characters of string `t` found within the first `i` characters of string `s`.
 *
 * dp[i][j] = dp[i - 1][j], s[i - 1] != t[j - 1]
 * dp[i][j] = dp[i - ][j - 1] + dp[i - 1][j], s[i - 1] == t[j - 1]
 *
 */
class Solution
{
public:
  int numDistinct(string s, string t)
  {
    int m = s.size(), n = t.size();

    vector<vector<unsigned>> dp(m + 1, vector<unsigned>(n + 1, 0));

    for (int i = 0; i < m; i++)
      dp[i][0] = 1;

    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[m][n];
  }
};

int main()
{
  return 0;
}