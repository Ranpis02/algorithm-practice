#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string reverseStr(string s, int k)
  {
    int n = s.size();
    for (int i = 0; i < n; i += 2 * k)
    {
      reverse(s.begin() + i, s.begin() + min(n, i + k));
    }

    return s;
  }
};

int main()
{
  string s = "abcdefg";
  Solution *sol = new Solution;
  sol->reverseStr(s, 2);
  return 0;
}