#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> parse(string s)
{
  vector<string> strs;
  stringstream ss(s);

  string str;
  while (ss >> str)
  {
    strs.push_back(str);
  }

  return strs;
}
int main()
{
  string str = "Alice Bob Charlie";
  vector<string> strs = parse(str);

  for (string str : strs)
  {
    cout << str << endl;
  }

  return 0;
}