#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> partitionLabels(string s)
  {
    int n = s.size();

    // unordered_map<char, int> mp;
    vector<int> maxRange(26, INT_MIN);

    for (int i = 0; i < n; i++)
    {
      maxRange[s[i] - 'a'] = max(maxRange[s[i] - 'a'], i);
    }

    vector<int> ans;
    int start = 0;
    int i = 0;

    while (i < n)
    {
      int k = maxRange[s[start] - 'a'];
      while (i <= k)
      {
        k = max(k, maxRange[s[i] - 'a']);
        i++;
      }

      ans.push_back(i - start);
      start = i;
    }

    return ans;
  }
};

int main()
{
  string s = "ababcbacadefegdehijhklij";

  Solution *sol = new Solution;
  sol->partitionLabels(s);

  return 0;
}