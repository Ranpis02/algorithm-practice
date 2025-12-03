#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int numDistinct(string s, string t)
  {
    int m = s.size(), n = t.size();

    vector<unsigned> dp(n + 1, 0);

    if (m < n)
      return 0;

    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
      int prev = 1;
      for (int j = 1; j <= n; j++)
      {
        int tmp = dp[j];
        if (s[i - 1] == t[j - 1])
          dp[j] += prev;

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