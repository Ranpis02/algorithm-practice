#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int m = s.size(), n = t.size();

    if (m < n)
      return "";

    unordered_map<char, int> mp;
    for (auto &ch : t)
    {
      mp[ch]++;
    }

    int l = n, r = m;

    int startIdx = -1, len = -1;
    while (l <= r)
    {
      int mid = l + ((r - l) >> 1);
      int idx = find(s, mid, mp);
      if (idx == -1)
      {
        l = mid + 1;
      }
      else
      {
        startIdx = idx;
        len = mid;
        r = mid - 1;
      }
    }

    if (startIdx == -1)
      return "";

    return s.substr(startIdx, len);
  }

  int find(const string &s, int len, unordered_map<char, int> mp)
  {
    int n = mp.size();
    for (int i = 0; i < len; i++)
    {
      char ch = s[i];
      if (mp.count(ch))
      {
        mp[ch]--;
      }
    }

    if (check(mp))
      return 0;

    for (int i = len; i < s.size(); i++)
    {
      char removeChar = s[i - len];
      char addChar = s[i];

      if (mp.count(removeChar))
        mp[removeChar]++;
      if (mp.count(addChar))
        mp[addChar]--;

      if (check(mp))
        return (i - len + 1);
    }

    return -1;
  }

  bool check(const unordered_map<char, int> &mp)
  {
    for (auto &[_, val] : mp)
    {
      if (val > 0)
        return false;
    }

    return true;
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