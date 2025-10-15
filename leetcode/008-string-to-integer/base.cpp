#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

/**
 * @brief 8. 字符串转换整数 (atoi)
 */
class Solution
{
public:
  int myAtoi(string s)
  {
    int i = 0, sign = 1;
    long long res = 0;

    // Remove the unused leading spaces
    while (i < s.size() && s[i] == ' ')
      i++;

    if (s[i] == '-')
    {
      sign = -1;
      i++;
    }
    else if (s[i] == '+')
    {
      i++;
    }

    // Check the current charcter is '+  or '-
    while (i < s.size())
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        res = res * 10 + (s[i] - '0');
        i++;
        if (res > INT32_MAX)
        {
          res = sign == 1 ? INT32_MAX : INT32_MIN;
          return res;
        }
      }
      else
      {
        break;
      }
    }
    res *= sign;

    return res;
  }
};

int main()
{
  Solution *s = new Solution();
  cout << s->myAtoi("   -042") << endl;
  return 0;
}
