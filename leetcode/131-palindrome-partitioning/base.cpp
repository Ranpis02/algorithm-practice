#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<string>> ans;
  vector<string> strs;
  vector<vector<char>> dp;

public:
  vector<vector<string>> partition(string s)
  {
    // Preprocess: use DP to judge whether the substring s[i..j] is a palingdrome
    int n = s.size();
    // vector<vector<bool>> dp(n, vector<bool>(n, false));
    // dp.resize(n);
    // for (int i = 0; i < n; i++)
    //   dp[i].resize(n, false);

    dp.assign(n, vector<char>(n, 0));

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i; j < n; j++)
      {
        if (s[i] == s[j] && ((j - i) < 2 || dp[i + 1][j - 1]))
        {
          dp[i][j] = true;
        }
      }
    }

    backtracking(s, 0);

    return ans;
  }

  void backtracking(const string &s, int startIdx)
  {
    if (startIdx == s.size())
    {
      ans.push_back(strs);
      return;
    }

    for (int i = startIdx; i < s.size(); i++)
    {
      if (!dp[startIdx][i])
        continue;

      // strs.push_back(string(s.begin() + startIdx, s.begin() + i + 1));
      strs.push_back(s.substr(startIdx, i - startIdx + 1));
      backtracking(s, i + 1);
      strs.pop_back();
    }
  }
};

int main()
{
  string s = "efe";

  Solution *sol = new Solution;
  sol->partition(s);

  return 0;
}