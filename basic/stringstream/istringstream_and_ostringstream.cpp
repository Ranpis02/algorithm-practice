#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * istringstream: input string stream, convert a string to different data types.
 *
 * - common operation: `>>`
 * - analogous operators: `cin`, `scanf`
 */
void istringstreamBasic()
{
  string data = "101 Alice 170";

  istringstream iss(data);

  int id;
  string name;
  double height;

  iss >> id >> name >> height;

  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Height: " << height << endl;
}

/**
 * ostringstream: output string stream
 *
 * - common operation: `<<`
 * - analogous operators: `cout`, `printf`
 */
void ostringstreamBasic()
{
  int id = 101;
  string name = "Alice";
  double height = 170;

  ostringstream oss;
  oss << id << ", " << name << ", " << height;

  string result = oss.str();

  cout << "serialize result: " << result << endl;
}

int main()
{
  istringstreamBasic();

  cout << endl;

  ostringstreamBasic();
  return 0;
}