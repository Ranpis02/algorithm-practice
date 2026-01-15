#include <bits/stdc++.h>

using namespace std;

static const pair<int, string> romanMap[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}};
class Solution
{
public:
  string intToRoman(int num)
  {
    string ans;

    for (auto &[val, str] : romanMap)
    {
      while (num >= val)
      {
        num -= val;
        ans += str;
      }

      if (num == 0)
        break;
    }

    return ans;
  }
};

int main()
{

  return 0;
}