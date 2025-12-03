#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int m = word1.size(), n = word2.size();

    if (m < n)
      return minDistance(word2, word1);

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
      int prev = 0;
      for (int j = 1; j <= n; j++)
      {
        int tmp = dp[j];
        if (word1[i - 1] == word2[j - 1])
          dp[j] = prev + 1;
        else
        {
          dp[j] = max(dp[j], dp[j - 1]);
        }
        prev = tmp;
      }
    }

    return m + n - dp[n] * 2;
  }
};

int main()
{
  return 0;
}