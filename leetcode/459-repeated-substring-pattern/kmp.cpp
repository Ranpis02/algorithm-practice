#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> buildNext(string &s)
  {
    int n = s.size();

    vector<int> next(n, 0);

    int j = 0;
    for (int i = 1; i < n; i++)
    {
      while (j > 0 && s[i] != s[j])
      {
        j = next[j - 1];
      }

      if (s[i] == s[j])
        j++;

      next[i] = j;
    }

    return next;
  }

  bool repeatedSubstringPattern(string s)
  {
    int n = s.size();

    vector<int> next = buildNext(s);

    int unitLen = n - next[n - 1];

    return next[n - 1] > 0 && (n % unitLen == 0);
  }
};

int main()
{
  string str = "abac";

  Solution *sol = new Solution;
  sol->repeatedSubstringPattern(str);

  return 0;
}