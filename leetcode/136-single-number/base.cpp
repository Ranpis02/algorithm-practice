#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Solution: based on the properties of XOR
 * 1. a ^ 0 = a
 * 2. a ^ a = 0
 */
class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int res = 0;
    for (int n : nums)
    {
      res ^= n;
    }
    return res;
  }
};

int main()
{

  return 0;
}