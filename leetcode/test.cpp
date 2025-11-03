#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main()
{
  vector<int> vec = {1, 2, 3, 4, 5};


  cout << typeid(vec).name() << endl;
  return 0;
}