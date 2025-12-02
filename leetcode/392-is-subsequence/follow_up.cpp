#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Sence 1: We need to determine whether many strings s1, s2, ..., sn
 * are subsequences of a very long and fixed string `t`.
 */
  class Solution
  {
  private:
    unordered_map<char, vector<int>> charIndices;

  public:
    vector<bool> areSubsequences(const vector<string> &strs, const string &t)
    {
      vector<bool> ans;

      charIndices.clear();
      // Build index map
      for (int i = 0; i < t.size(); i++)
      {
        charIndices[t[i]].push_back(i);
      }

      for (const auto &str : strs)
      {
        ans.push_back(isSubsequence(str));
      }

      return ans;
    }

    bool isSubsequence(const string &s)
    {
      int charIdx = -1;

      for (const auto &ch : s)
      {
        if (!charIndices.count(ch))
          return false;

        vector<int> &indices = charIndices[ch];
        auto it = upper_bound(indices.begin(), indices.end(), charIdx);

        if (it == indices.end())
          return false;

        charIdx = *it;
      }

      return true;
    }
  };

int main()
{
  vector<string> strs = {"ac", "ab", "cb", "ba"};

  string t = "ababc";

  Solution *s = new Solution;
  auto ans = s->areSubsequences(strs, t);

  for (auto v : ans)
  {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}