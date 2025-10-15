#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows == 1 || s.length() <= numRows)
      return s;

    string str_zigzag = "";
    for (int i = 0; i < numRows; i++)
    {
      int j = i;

      if (j < s.length())
      {
        str_zigzag += s[j];
        cout << "current pos: [ " << j << " ]" << ": " << s[j] << endl;
      }
      else
        break;

      while (true)
      {
        int x = 2 * (numRows - 1 - i);

        if (x != 0 && j + x < s.length())
        {
          j += x;
          str_zigzag += s[j];
          cout << "current pos: [ " << j << " ]" << ": " << s[j] << endl;
        }
        else if (j + x >= s.length())
        {
          break;
        }

        int y = 2 * i;

        if (y != 0 && j + y < s.length())
        {
          j += y;
          str_zigzag += s[j];
          cout << "current pos: [ " << j << " ]" << ": " << s[j] << endl;
        }
        else if (j + y >= s.length())
        {
          break;
        }
      }
    }

    return str_zigzag;
  }
};

int main()
{
  string s = "AB";
  int numRows = 1;

  Solution *sol = new Solution;
  string conversion = sol->convert(s, numRows);

  cout << conversion << endl;
  return 0;
}