#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isPalindrome(int x)
  {
    // Caution: When reversing a number, leading 0s are lost. Therefore, numbers ending in zero requires special handling.
    if (x < 0 || (x % 10 == 0 && x != 0))
      return false;
    int reversed_x = 0;

    while (x > reversed_x)
    {
      reversed_x = reversed_x * 10 + x % 10;
      x /= 10;
    }

    return (reversed_x == x) || (reversed_x / 10 == x);
  }
};

int main()
{
  int x = 12112;

  Solution *sol = new Solution;
  cout << sol->isPalindrome(x) << endl;

  return 0;
}