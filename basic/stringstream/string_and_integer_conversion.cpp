#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string toString(int digit)
{
  stringstream ss;
  ss << digit; // read
  return ss.str();
}

int toInteger(string str)
{
  int num;
  stringstream ss;
  ss >> num;
  return num;
}

int main()
{
  string str = "123";
  int num = toInteger(str);
  cout << num << endl;

  string string_conversion = toString(num);
  cout << string_conversion << endl;

  return 0;
}