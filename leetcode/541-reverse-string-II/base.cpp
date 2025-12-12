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
    int p = n / (2 * k);
    for (int i = 0; i < p; i++)
    {
      reverse(s.begin() + i * (2 * k), s.begin() + i * (2 * k) + k);
    }

    int remain = n - p * 2 * k;
    if (remain < k)
    {
      reverse(s.begin() + p * 2 * k, s.end());
    }
    else
    {
      reverse(s.begin() + p * 2 * k, s.begin() + p * 2 * k + k);
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