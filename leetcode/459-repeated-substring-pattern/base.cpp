#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 1. Concatenate the string withitself, which simulates all possible rotations of the string.
 *
 * 2. Remove the first and last characters to avoid matching the origin string ar very begining or end.
 *
 * 3. Check if the original string `s` exists in this new string.
 */
class Solution
{
public:
  bool repeatedSubstringPattern(string s)
  {
    string ss = s + s;

    return ss.substr(1, ss.size() - 2).find(s) != string::npos;
  }
};

int main()
{
  return 0;
}