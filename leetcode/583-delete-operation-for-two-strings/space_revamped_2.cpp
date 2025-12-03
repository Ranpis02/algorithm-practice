#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * dp[i][j]: the minimum number of deletions required to
 * make the first `i` characters of `word1` and the first `j` characters of word2 identical.
 *
 * Transition Equation:
 * 1. dp[i][j] = dp[i - 1][j - 1], s[i - 1] == t[j - 1];
 * 2. dp[i][j] = max{dp[i - 1][j] + 1, d[i][j - 1] + 1}
 */
class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int m = word1.size(), n = word2.size();

    vector<int> dp(n + 1, 0);

    for (int i = 0; i <= n; i++)
      dp[i] = i;

    for (int i = 1; i <= m; i++)
    {
      int prev = dp[0];
      dp[0] = i;

      for (int j = 1; j <= n; j++)
      {
        int tmp = dp[j];
        if (word1[i - 1] == word2[j - 1])
        {
          dp[j] = prev;
        }
        else
        {
          dp[j] = min(dp[j - 1], dp[j]) + 1;
        }
        prev = tmp;
      }
    }

    return dp[n];
  }
};

int main()
{
  string word1 = "leetcode", word2 = "etco";

  Solution *s = new Solution;
  s->minDistance(word1, word2);

  return 0;
}