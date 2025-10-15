#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows < 2)
      return s;

    vector<string> rows(numRows);

    int flag = -1, i = 0;

    for (char c : s)
    {
      rows[i] += c;
      if (i == 0 || i == numRows - 1)
        flag = -flag;

      i += flag;
    }

    string res = "";
    for (const string &row : rows)
    {
      res += row;
    }

    return res;
  }
};

int main()
{
  string s = "PAYPALISHIRING";
  int numRows = 3;

  Solution *sol = new Solution;

  cout << sol->convert(s, numRows) << endl;
  return 0;
}