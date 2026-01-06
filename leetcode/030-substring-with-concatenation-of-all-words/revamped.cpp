#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    int word_num = words.size(), word_len = words[0].size();
    int str_len = s.size();

    if (str_len < word_num * word_len)
      return {};

    unordered_map<string, int> mp;
    vector<int> ans;

    for (int i = 0; i < word_num; i++)
    {
      mp[words[i]]++;
    }

    for (int i = 0; i < word_len; i++)
    {
      int cnt = mp.size();
      unordered_map<string, int> store(mp);

      int first_end = i + word_num * word_len;
      if (first_end > str_len)
        break;

      for (int j = i; j < first_end; j += word_len)
      {
        string str = s.substr(j, word_len);
        if (!store.count(str))
          continue;

        if (store[str] == 1)
        {
          cnt--;
        }
        else if (store[str] == 0)
        {
          cnt++;
        }

        store[str]--;
      }

      if (cnt == 0)
        ans.push_back(i);

      for (int j = first_end; j + word_len <= str_len; j += word_len)
      {
        string pop_str = s.substr(j - word_len * word_num, word_len);
        string push_str = s.substr(j, word_len);

        if (store.count(pop_str))
        {
          if (store[pop_str] == 0)
            cnt++;
          else if (store[pop_str] == -1)
            cnt--;

          store[pop_str]++;
        }

        if (store.count(push_str))
        {
          if (store[push_str] == 1)
            cnt--;
          else if (store[push_str] == 0)
            cnt++;

          store[push_str]--;
        }

        if (cnt == 0)
          ans.push_back(j - word_len * (word_num - 1));
      }
    }

    return ans;
  }
};

int main()
{
  vector<string> words = {"word", "good", "best", "good"};
  string s = "wordgoodgoodgoodbestword";

  Solution *sol = new Solution;
  sol->findSubstring(s, words);

  return 0;
}