#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Since two strings that are anagrams contains the same characters, sorting them will produce the identical results.
class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> mp;
    for (string str : strs)
    {
      string s(str);
      sort(s.begin(), s.end());
      if (mp.count(s))
      {
        mp[s].push_back(str);
      }
      else
      {
        mp.insert({s, vector<string>{str}});
      }
    }

    vector<vector<string>> ans;

    for (auto &v : mp)
    {
      ans.push_back(v.second);
    }

    return ans;
  }
};

int main()
{

  return 0;
}