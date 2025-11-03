#include <iostream>
#include <string>

using namespace std;

/**
 * @brief 9. Palindrome Number
 *
 * Solution idea: convert to string and use two pointers to check
 * - cons: create a extra non-constant space
 */
class Solution
{
public:
  bool isPalindrome(int x)
  {
    string s = to_string(x);
    int l = 0, r = s.size() - 1;

    for (int i = 0; i < s.size() / 2; i++)
    {
      if (s[l++] != s[r--])
        return false;
    }

    return true;
  }
};

int main()
{
  int x = 121;
  Solution *s = new Solution();
  cout << s->isPalindrome(x) << endl;

  bool res = true;
  cout << res << endl;
  return 0;
}