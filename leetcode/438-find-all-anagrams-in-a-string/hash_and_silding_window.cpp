#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    int n = s.size(), m = p.size();
    if (n < m)
      return {};

    vector<int> hashTable(26, 0);
    vector<int> checkTable(26, 0);
    vector<int> ans;

    for (int i = 0; i < p.size(); i++)
    {
      hashTable[p[i] - 'a']++;
      checkTable[s[i] - 'a']++;
    }

    if (hashTable == checkTable)
      ans.push_back(0);
    for (int i = 1; i <= n - m; i++)
    {
      checkTable[s[i - 1] - 'a']--;
      checkTable[s[i + m - 1] - 'a']++;
      if (hashTable == checkTable)
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