#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int rangeBitwiseAnd(int left, int right)
  {
    while (left < right)
    {
      right &= (right - 1);
    }

    return right;
  }
};

int main()
{

  return 0;
}