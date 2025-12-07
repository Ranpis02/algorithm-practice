#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    int n = s.size();

    for (int i = 1; i <= n / 2; i++)
    {
      if (n % i == 0)
      {
        bool match = true;

        for (int j = 0; j < n - i; j++)
        {
          if (s[j] != s[j + i])
          {
            match = false;
            break;
          }
        }

        if (match)
          return true;
      }
    }

    return false;
  }
};

int main()
{
  string str = "abac";

  Solution *sol = new Solution;
  sol->repeatedSubstringPattern(str);

  return 0;
}