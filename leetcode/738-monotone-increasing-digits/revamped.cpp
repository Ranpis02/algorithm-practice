#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int monotoneIncreasingDigits(int n)
  {
    string s = to_string(n);

    int m = s.size();
    int flag = m;

    for (int i = m - 1; i > 0; i--)
    {
      if (s[i - 1] > s[i])
      {
        s[i - 1]--;
        flag = i;
      }
    }

    for (int i = flag; i < m; i++)
    {
      s[i] = '9';
    }

    return stoi(s);
  }
};

int main()
{

  return 0;
}