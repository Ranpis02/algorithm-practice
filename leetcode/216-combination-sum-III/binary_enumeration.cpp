#include <iostream>
#include <vector>

using namespace std;

/**
 * Binary enumeration is practical only for small `n`, typically n < 25.
 */
class Solution
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    int sum;

    vector<vector<int>> ans;
    vector<int> tmp(k);

    for (int i = 0; i < (1 << 9); i++)
    {
      if (__builtin_popcount(i) != k)
        continue;

      sum = 0;
      int t = i;
      int idx = 0;
      for (int j = 1; j <= 9; j++)
      {
        if (t & 1)
        {
          sum += j;
          if (sum > n)
            break;

          tmp[idx++] = j;
        }

        if (idx == k)
          break;

        t >>= 1;
      }

      if (sum == n)
        ans.push_back(tmp);
    }

    return ans;
  }

  // int countOnes(int x)
  // {
  //   int cnt = 0;
  //   while (x)
  //   {
  //     x &= (x - 1);
  //     cnt++;
  //   }

  //   return cnt;
  // }
};

int main()
{
  Solution *s = new Solution;
  s->combinationSum3(4, 1);
  return 0;
}