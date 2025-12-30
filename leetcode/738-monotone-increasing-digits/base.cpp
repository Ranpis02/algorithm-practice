#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int monotoneIncreasingDigits(int n)
  {
    vector<int> digit;
    string s = to_string(n);

    int len = s.size();

    digit.assign(len, 9);
    digit[0] = s[0] - '0';

    int idx = 0;
    int t = 0;

    while (idx < len)
    {
      while (true)
      {
        int acc = t;
        for (int i = idx; i < len; i++)
        {
          acc *= 10;
          acc += digit[idx];
        }

        if (acc <= n)
          break;
        else
        {
          digit[idx]--;
        }
      };

      t *= 10;
      t += digit[idx];

      idx++;
    }

    return t;
  }
};

int main()
{
  int n = 332;

  Solution *sol = new Solution;
  sol->monotoneIncreasingDigits(n);

  return 0;
}