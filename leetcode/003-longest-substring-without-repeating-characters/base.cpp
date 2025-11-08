#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.size() == 0)
      return 0;

    // vector<bool> a(26, false);
    unordered_set<char> seen;

    int i = 0, ans = 1;
    for (int j = 0; j < s.size(); j++)
    {
      if (!seen.count(s[j]))
      {
        seen.insert(s[j]);
        // if ((j - i + 1) > ans)
        //   ans++;
        ans = max(j - i + 1, ans);
      }
      else
      {
        while (i <= j)
        {
          seen.erase(s[i]);
          i++;
          if (!seen.count(s[j]))
          {
            seen.insert(s[j]);
            break;
          }
        }
      }
    }

    return ans;
  }
};

class Solution_2
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_set<char> seen;

    int i = 0, ans = 0;
    for (int j = 0; j < s.size(); j++)
    {
      while (seen.count(s[j]))
        seen.erase(s[i++]);

      seen.insert(s[j]);

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};

int main()
{
  return 0;
}