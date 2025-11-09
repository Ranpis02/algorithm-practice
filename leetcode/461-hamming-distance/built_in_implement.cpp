#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int hammingDistance(int x, int y)
  {
    int res = __builtin_popcount(x ^ y);

    return res;
  }
};

int main()
{
  return 0;
}