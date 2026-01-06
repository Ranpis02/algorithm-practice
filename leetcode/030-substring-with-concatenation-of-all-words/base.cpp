#include <bits/stdc++.h>

using namespace std;

class Solution_TLE
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    int n = words.size(), word_len = words[0].size();
    int str_len = s.size();
    int total_len = n * word_len;

    if (total_len > str_len)
      return {};

    vector<int> ans;
    unordered_map<string, int> mp;

    for (auto &word : words)
    {
      mp[word]++;
    }

    for (int i = 0; i < str_len - total_len + 1; i++)
    {
      unordered_map<string, int> m_check(mp);
      int cnt = mp.size();

      for (int j = i; j < i + total_len; j += word_len)
      {
        string str = s.substr(j, word_len);

        if (!m_check.count(str))
          break;

        if (m_check[str] == 1)
          cnt--;
        m_check[str]--;
      }

      if (cnt == 0)
        ans.push_back(i);
    }

    return ans;
  }

};

int main()
{

  return 0;
}