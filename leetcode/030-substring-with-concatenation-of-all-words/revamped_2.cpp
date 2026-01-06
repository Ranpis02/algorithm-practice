#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    vector<int> ans;

    if (words.empty())
      return ans;

    int word_num = words.size(), word_len = words[0].size();
    int str_len = s.size();

    if (word_num * word_len > str_len)
      return ans;

    unordered_map<string, int> mp;

    for (auto &word : words)
    {
      mp[word]++;
    }

    for (int i = 0; i < word_len; i++)
    {
      unordered_map<string, int> window;

      int left = i, right = i;
      int cnt = 0;

      while (right + word_len <= str_len)
      {
        string str = s.substr(right, word_len);
        right += word_len;

        if (!mp.count(str))
        {
          left = right;

          window.clear();
          cnt = 0;
        }
        else
        {
          window[str]++;

          cnt++;

          while (window[str] > mp[str])
          {
            string str_left = s.substr(left, word_len);
            window[str_left]--;
            cnt--;
            left += word_len;
          }

          if (cnt == word_num)
            ans.push_back(left);
        }
      }
    }

    return ans;
  }
};

int main()
{
  Solution *sol = new Solution;

  vector<string> words = {"bar", "foo", "the"};
  string s = "barfoofoobarthefoobarman";
  sol->findSubstring(s, words);

  return 0;
}