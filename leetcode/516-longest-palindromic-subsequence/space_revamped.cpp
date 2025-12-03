#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * There is another approach: reverse the original string and compute the LCS between the two strings.
 */
class Solution
{
public:
  int longestPalindromeSubseq(string s)
  {
    int n = s.size();

    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
      dp[i] = 1;
      int prev = 0;
      for (int j = i + 1; j < n; j++)
      {
        int tmp = dp[j];
        if (s[i] == s[j])
        {
          dp[j] = prev + 2;
        }
        else
        {
          dp[j] = max(dp[j], dp[j - 1]);
        }
        prev = tmp;
      }
    }

    return dp[n - 1];
  }
};

int main()
{
  return 0;
}