#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * dp[i][j]: represents the length of the longest palindromic subsequence within the s[i..j].
 *
 * (1) dp[i][j] = dp[i + 1][j -1] + 2, s[i] == s[j]
 * (2) d[i][j] = max{ dp[i + 1][j], dp[i][j - 1] }, s[i] != s[j]
 *
 * Note: when i > j, the substring s[i..j] is empty, so it LPS value is 0.
 */
class Solution
{
public:
  int longestPalindromeSubseq(string s)
  {
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
      dp[i][i] = 1;
      for (int j = i + 1; j < n; j++)
      {
        if (s[i] == s[j])
        {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        }
        else
        {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[0][n - 1];
  }
};

int main()
{
  return 0;
}