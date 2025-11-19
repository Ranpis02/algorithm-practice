#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numTrees(int n)
  {
    if (n == 1)
      return 1;

    vector<int> dp(21, 0);

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= i; j++)
        dp[i] += dp[j - 1] * dp[i - j];

    return dp[n];
  }
};

int main()
{
  Solution *s = new Solution;
  vector<int> ves;
  for (int i = 1; i <= 19; i++)
  {
    cout << s->numTrees(i) << endl;
  }
  return 0;
}