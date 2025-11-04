#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main()
{
  srand(time(0));
  cout << rand() % 10 << " ";
  cout << rand() % 10 << " ";
  cout << rand() % 10 << endl;

  return 0;
}