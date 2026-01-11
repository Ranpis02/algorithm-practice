#include <bits/stdc++.h>

using namespace std;

/**
 * dp[i][j] represent whether the first i + j characters of s3 can be formed by interleaving the first i characters of s1 and the first j characters of s2.
 *
 * dp[i][j] = true, when s3[i + j - 1] == s1[i - 1] || s3[i + j - 1] == s2[j - 1]
 */
class Solution
{
public:
  bool isInterleave(string s1, string s2, string s3)
  {
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();

    if (len1 + len2 != len3)
      return false;

    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));

    dp[0][0] = true;

    for (int i = 0; i <= len1; i++)
    {
      for (int j = 0; j <= len2; j++)
      {
        if (i > 0 && s1[i - 1] == s3[i + j - 1])
        {
          dp[i][j] = dp[i][j] || dp[i - 1][j];
        }

        if (j > 0 && s2[j - 1] == s3[i + j - 1])
        {
          dp[i][j] = dp[i][j] || dp[i][j - 1];
        }
      }
    }

    return dp[len1][len2];
  }
};

int main()
{
  string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";

  Solution *sol = new Solution;
  sol->isInterleave(s1, s2, s3);

  return 0;
}