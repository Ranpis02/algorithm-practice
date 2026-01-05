#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    int carry = 0;

    int m = a.size(), n = b.size();

    string ans = "";
    int i = 0;
    while (i < m || i < n)
    {
      int x_1 = i < m ? a[m - i - 1] - '0' : 0;

      int x_2 = i < n ? b[n - i - 1] - '0' : 0;

      int total = x_1 + x_2 + carry;

      carry = total / 2;

      ans += (total % 2) + '0';
      i++;
    }

    if (carry == 1)
      ans += '1';

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main()
{

  return 0;
}