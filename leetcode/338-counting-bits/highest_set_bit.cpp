#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * My version
 */
class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> vec(n + 1);
    if (n >= 1)
      vec[1] = 1;

    if (n >= 2)
      vec[2] = 1;

    for (int i = 3; i <= n; i++)
    {
      int p = highestPowerOf2(i);
      vec[i] = vec[i - p] + 1;
    }

    return vec;
  }

private:
  int highestPowerOf2(int n)
  {
    int p = 1;
    while (p * 2 <= n)
    {
      p *= 2;
    }

    return p;
  }
};

/**
 * Official version
 */
class OfficialSolution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> vec(n + 1);
    int highBit = 0;
    for (int i = 1; i <= n; i++)
    {
      // Check whether i is a power of 2
      // Note the precedence of bitwise operators; avoid writing it as `i & (i - 1) ==0`
      if ((i & (i - 1)) == 0)
      {
        highBit = i;
      }
      vec[i] = vec[i - highBit] + 1;
    }

    return vec;
  }
};

int main()
{
  int n = 5;
  OfficialSolution *s = new OfficialSolution;

  vector<int> res = s->countBits(n);
  return 0;
}