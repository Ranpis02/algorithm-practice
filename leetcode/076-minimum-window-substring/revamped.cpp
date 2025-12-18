#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int m = s.size(), n = t.size();

    if (m < n)
      return "";

    int need[128] = {0};

    for (char ch : t)
      need[ch]++;

    int cnt = n;
    int l = 0, r = 0;

    int minLen = INT_MAX;
    int startIdx = -1;

    while (r < m)
    {
      need[s[r]]--;
      if (need[s[r]] >= 0)
        cnt--;

      while (cnt == 0)
      {
        if ((r - l + 1) < minLen)
        {
          minLen = r - l + 1;
          startIdx = l;
        }

        if (need[s[l]] == 0)
        {
          cnt++;
        }

        need[s[l]]++;
        l++;
      }

      r++;
    }
    return startIdx == -1 ? "" : s.substr(startIdx, minLen);
  }
};

int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";
  Solution *sol = new Solution;
  sol->minWindow(s, t);
  return 0;
}