#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minimumDeleteSum(string s1, string s2)
  {
    int n = s1.size(), m = s2.size();

    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= m; i++)
      dp[i] = dp[i - 1] + s2[i - 1];

    // int acc = 0;
    for (int i = 1; i <= n; i++)
    {
      int diag = dp[0];
      dp[0] += s1[i - 1];

      for (int j = 1; j <= m; j++)
      {
        int tmp = dp[j];
        // if (s1[i - 1] == s2[j - 1])
        // {
        //   dp[j] = diag;
        // }
        // else
        // {
        //   dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
        // }
        dp[j] = s1[i - 1] == s2[j - 1] ? diag : min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
        diag = tmp;
      }
    }

    return dp[m];
  }
};

int main()
{

  return 0;
}