#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
      dp[i][0] = (int)s1[i - 1] + dp[i - 1][0];
    }

    for (int i = 1; i <= m; i++)
    {
      dp[0][i] = (int)s2[i - 1] + dp[0][i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        char ch1 = s1[i - 1], ch2 = s2[j - 1];
        int num1 = (int)ch1, num2 = (int)ch2;
        dp[i][j] = min({dp[i - 1][j - 1] + num1 + num2, dp[i - 1][j] + num1, dp[i][j - 1] + num2});
        if (ch1 == ch2)
        {
          dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
        }
      }
    }

    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= m; j++)
      {
        cout << dp[i][j] << "\t";
      }

      cout << endl;
    }
    return dp[n][m];
  }
};

int main()
{
  string s1 = "sea", s2 = "eat";

  Solution *sol = new Solution;
  sol->minimumDeleteSum(s1, s2);

  return 0;
}