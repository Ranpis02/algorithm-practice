#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    removeExtraSpaces(s);

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != ' ')
      {
        int start = i;

        while (i < s.size() && s[i] != ' ')
        {
          i++;
        }

        reverse(s.begin() + start, s.begin() + i);
      }
    }

    return s;
  }

  void removeExtraSpaces(string &s)
  {
    int slow = 0;

    for (int fast = 0; fast < s.size(); fast++)
    {
      if (s[fast] != ' ')
      {
        if (slow != 0)
        {
          s[slow++] = ' ';
        }

        while (fast < s.size() && s[fast] != ' ')
        {
          s[slow++] = s[fast++];
        }
      }
    }

    s.resize(slow);
  }
};

int main()
{
  return 0;
}