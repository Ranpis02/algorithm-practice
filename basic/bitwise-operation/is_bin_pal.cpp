#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

/**
 * Flip as a whole, then compare
 */
class Solution_1
{

public:
  bool isBinaryPalindrome(int x)
  {
    if (x < 0)
      return false;

    int y = 0;
    int t = x;
    while (t)
    {
      y = (y << 1) | (t & 1);
      t >>= 1;
    }

    return x == y;
  }
};

class Solution_2
{
  bool isBinaryPalindrome(int x)
  {
    if (x < 0)
      return false;

    string s = bitset<64>(x).to_string();
    s = s.substr(s.find('1'));

    string t = s;

    reverse(t.begin(), t.end());

    return s == t;
  }
};

int main()
{

  return 0;
}