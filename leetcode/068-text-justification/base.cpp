#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    int i = 0, n = words.size();
    int len;
    vector<string> ans;

    while (i < n)
    {
      len = maxWidth;

      string sen;
      sen += words[i];
      len -= words[i].size();
      // int spaces = 0;
      i++;

      vector<string> connect;
      while (i < n && len >= words[i].size() + 1)
      {
        connect.push_back(words[i]);
        len -= words[i].size() + 1;
        i++;
      }

      int word_num = connect.size();
      if (i != n && word_num > 0)
      {
        int space_num = len + connect.size();

        int space_interval_num = space_num / word_num;
        int remain = space_num % word_num;

        string interval(space_interval_num, ' ');
        for (auto &str : connect)
        {
          sen += interval;
          if (remain > 0)
          {
            sen += ' ';
            remain--;
          }

          sen += str;
        }
      }
      else
      {
        for (auto &str : connect)
        {
          sen += ' ';
          sen += str;
        }

        sen += string(maxWidth - sen.size(), ' ');
      }

      ans.push_back(sen);
    }

    return ans;
  }
};

int main()
{
  vector<string> strs = {"This", "is", "an", "example", "of", "text", "justification."};

  Solution *sol = new Solution;

  sol->fullJustify(strs, 16);

  return 0;
}