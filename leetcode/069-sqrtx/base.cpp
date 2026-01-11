#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {
    int left = 0, right = x;

    int ans;
    while (left <= right)
    {
      long mid = left + ((right - left) >> 1);

      if (mid * mid <= x)
      {
        left = mid + 1;
        ans = mid;
      }
      else
      {
        right = mid - 1;
      }
    }

    return ans;
  }
};

int main()
{

  return 0;
}