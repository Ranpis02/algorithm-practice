#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  int countSubstrings(string s)
  {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
      expandAroundCenter(s, i, i, cnt);
      expandAroundCenter(s, i, i + 1, cnt);
    }

    return cnt;
  }

  void expandAroundCenter(const string &s, int l, int r, int &cnt)
  {
    while (l >= 0 && r < s.size() && s[l--] == s[r++])
      cnt++;
  }
};

int main()
{
  string s = "abc";

  Solution *sol = new Solution;
  sol->countSubstrings(s);
  return 0;
}