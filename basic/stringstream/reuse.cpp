#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{

  stringstream ss;
  for (int i = 0; i < 3; i++)
  {
    ss.str(""); // replace with the empty string
    ss.clear(); // reset the state

    ss << "Iteration: " << i;
    cout << ss.str() << endl;
  }

  return 0;
}