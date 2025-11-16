#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    int n = s.size(), m = p.size();
    if (n < m)
      return {};

    // Store the difference for each letter (window - p)
    vector<int> diff(26);
    // Number of letters whose counts differ between the window and p
    int diffCount = 0;

    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
      diff[s[i] - 'a']++;
      diff[p[i] - 'a']--;
    }

    for (int val : diff)
      if (val != 0)
        diffCount++;

    if (diffCount == 0)
      ans.push_back(0);

    for (int i = 1; i <= n - m; i++)
    {
      if (diff[s[i - 1] - 'a'] == 1)
      {
        diffCount--;
      }
      else if (diff[s[i - 1] - 'a'] == 0)
      {
        diffCount++;
      }

      diff[s[i - 1] - 'a']--;

      if (diff[s[i + m - 1] - 'a'] == -1)
      {
        diffCount--;
      }
      else if (diff[s[i + m - 1] - 'a'] == 0)
      {
        diffCount++;
      }

      diff[s[i + m - 1] - 'a']++;

      if (diffCount == 0)
        ans.push_back(i);
    }

    return ans;
  }
};

int main()
{

  string s = "abab";
  string p = "ab";

  Solution *sol = new Solution;
  vector<int> ans = sol->findAnagrams(s, p);
  return 0;
}