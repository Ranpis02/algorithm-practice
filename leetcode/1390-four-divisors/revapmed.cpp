#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int sumFourDivisors(vector<int> &nums)
  {
    int ans = 0;
    for (int num : nums)
    {
      if (num < 6)
        continue;

      int cnt = 0;
      int sum = 0;

      for (int i = 1; i * i <= num; i++)
      {
        if (num % i == 0)
        {
          cnt++;
          sum += i;

          if (i * i != num)
          {
            cnt++;
            sum += num / i;
          }
        }
      }

      if (cnt == 4)
        ans += sum;
    }

    return ans;
  }
};

int main()
{

  return 0;
}