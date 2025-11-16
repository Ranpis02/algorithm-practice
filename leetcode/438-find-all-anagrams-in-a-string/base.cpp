#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution_TLE
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    int n = s.size(), m = p.size();
    if (n < m)
      return {};
    unordered_set<char> uniqueSet;
    string pc = p;
    vector<int> ans;

    sort(pc.begin(), pc.end());

    for (char ch : p)
    {
      uniqueSet.insert(ch);
    }

    for (int i = 0; i <= s.size() - p.size(); i++)
    {
      if (uniqueSet.count(s[i]))
      {
        string sc = s.substr(i, m);
        sort(sc.begin(), sc.end());
        if (sc == pc)
          ans.push_back(i);
      }
    }

    return ans;
  }
};
int main()
{

  return 0;
}