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

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int i = 0; i <= n; i++)
      prev[i] = i;

    for (int i = 1; i <= m; i++)
    {
      curr[0] = i;
      for (int j = 1; j <= n; j++)
      {
        if (word1[i - 1] == word2[j - 1])
        {
          curr[j] = prev[j - 1];
        }
        else
        {
          curr[j] = min(curr[j - 1], prev[j]) + 1;
        }
      }
      prev.swap(curr);
    }

    return prev[n];
  }
};

int main()
{
  string word1 = "leetcode", word2 = "etco";

  Solution *s = new Solution;
  s->minDistance(word1, word2);

  return 0;
}