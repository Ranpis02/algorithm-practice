#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    int n = s.size();
    vector<bool> dp(n + 1, false);

    dp[0] = true;

    // vector<vector<bool>> p;

    for (int i = 0; i <= n; i++)
    {
      // vector<bool> t;
      for (string &word : wordDict)
      {
        int len = word.size();
        if (i >= len && dp[i - len] && wordSet.count(s.substr(i - len, len)))
        {
          dp[i] = true;
        }
        // t.push_back(dp[i]);
      }

      // p.push_back(t);
    }

    // for (int i = 0; i < wordDict.size(); i++)
    // {
    //   for (int j = 0; j <= n; j++)
    //   {
    //     cout << p[j][i] << " ";
    //   }
    //   cout << endl;
    // }

    return dp[n];
  }
};

int main()
{
  string str = "applepenapple";

  vector<string> wordDict = {"apple", "pen"};

  Solution *s = new Solution;
  s->wordBreak(str, wordDict);

  return 0;
}