#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int m = text1.size(), n = text2.size();

    if (m < n)
      return longestCommonSubsequence(text2, text1);

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
      int prev = 0;
      for (int j = 1; j <= n; j++)
      {
        int tmp = dp[j];
        if (text1[i - 1] == text2[j - 1])
          dp[j] = prev + 1;
        else
        {
          dp[j] = max(dp[j], dp[j - 1]);
        }
        prev = tmp;
      }
    }

    return dp[n];
  }
};

int main()
{
  return 0;
}