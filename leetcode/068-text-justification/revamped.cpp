#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    int i = 0;
    int n = words.size();
    vector<string> ans;

    while (i < n)
    {
      // [left, right) represents the range that contains the words in current sentence.
      int left = i;
      int crrLineLen = 0;

      while (i < n && crrLineLen + words[i].size() + (i - left) <= maxWidth)
      {
        crrLineLen += words[i].size();
        i++;
      }

      string line;
      int wordCnt = i - left;

      if (i == n || wordCnt == 1)
      {
        for (int j = left; j < i; j++)
        {
          line += words[j];

          if (j < i - 1)
            line += ' ';
        }

        line += string(maxWidth - line.size(), ' ');
      }
      else
      {
        int gaps = wordCnt - 1;
        int spaceCnt = maxWidth - crrLineLen;
        int perSpace = spaceCnt / gaps;
        int extra = spaceCnt % gaps;

        string basicSpace(perSpace, ' ');
        for (int j = left; j < i; j++)
        {
          line += words[j];

          if (j < i - 1)
          {
            line += basicSpace;
            if (extra > 0)
            {
              line += ' ';
              extra--;
            }
          }
        }
      }

      ans.push_back(line);
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