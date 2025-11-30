#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int findMaxForm(vector<string> &strs, int m, int n)
  {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto str : strs)
    {
      auto [zeros, ones] = countZerosAndOnes(str);
      for (int i = m; i >= zeros; i--)
      {
        for (int j = n; j >= ones; j--)
        {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }

    // for (int i = 0; i <= m; i++)
    // {
    //   for (int j = 0; j <= n; j++)
    //   {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    return dp[m][n];
  }

  /**
   * - first: The number of 0s.
   * - second: The number of 1s.
   */
  pair<int, int> countZerosAndOnes(string str)
  {
    int zeroCnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
      if (str[i] == '0')
        zeroCnt++;
    }

    return {zeroCnt, str.size() - zeroCnt};
  }
};
int main()
{
  vector<string> str = {"10", "0001", "111001", "1", "0"};

  Solution *s = new Solution;
  s->findMaxForm(str, 5, 3);
  // auto p = s->countZerosAndOnes("1000");

  // cout << p.first << " " << p.second << endl;
  return 0;
  ;
}