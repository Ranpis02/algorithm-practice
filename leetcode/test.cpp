#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int countOnes(int n)
{
  int cnt = 0;
  while (n > 0)
  {
    if (n & 1)
    {
      cnt++;
    }
    n >>= 1;
  }

  return cnt;
}

int main()
{
  int n = 11;
  cout << countOnes(n) << endl;

  return 0;
}