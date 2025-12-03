#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * dp[i][j]: represents whether the substring [i..j] is a palindrome
 *
 * dp[i][j] = (s[i] == s[j]) ∧ ((j - i < 2) ∨ d[i + 1][j - 1])
 *
 */
class Solution
{
public:
  int countSubstrings(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, false));

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i; j < n; j++)
      {
        if (s[i] == s[j] && (((j - i) < 2) || dp[i + 1][j - 1]))
        {
          dp[i][j] = true;
          cnt++;
        }
      }
    }

    return cnt;
  }
};

int main()
{

  return 0;
}