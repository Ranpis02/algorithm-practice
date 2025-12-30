#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> partitionLabels(string s)
  {
    int n = s.size();

    vector<int> last(26, -1);

    for (int i = 0; i < n; i++)
    {
      last[s[i] - 'a'] = i;
    }

    int maxPos = 0;
    int start = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      maxPos = max(maxPos, last[s[i] - 'a']);

      if (i == maxPos)
      {
        ans.push_back(i - start + 1);
        start = i + 1;
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}