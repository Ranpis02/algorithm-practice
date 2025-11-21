#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> parse_csv(string s)
{

  stringstream ss(s);
  string str;
  vector<string> strs;

  while (getline(ss, str, ','))
  {
    strs.push_back(str);
  }

  return strs;
}
int main()
{
  string str = "Alice,Bob,Charlie";
  vector<string> strs = parse_csv(str);
  for (string str : strs)
  {
    cout << str << endl;
  }

  return 0;
}