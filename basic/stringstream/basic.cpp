#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  // Declare a stringstream variable
  stringstream ss; // default constructor

  // Parameterized constructor
  stringstream sss("Hello, World!");

  // Write operation
  ss << 123 << " " << 456 << " abc";
  string s = ss.str();
  cout << s << endl;

  // Read operation(whitespace-separated input)
  int a, b;
  string c;
  ss >> a >> b >> c;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;

  // Retrieve the underlying string
  string val = ss.str();

  cout << "val: " << val << endl;

  // Set the underlying string
  ss.str("a b c");

  val = ss.str();
  cout << "val: " << val << endl;

  // Clear the state flags(EOF)
  

  return 0;
}