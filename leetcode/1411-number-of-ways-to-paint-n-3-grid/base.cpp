#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
private:
  static const int MOD = 1e9 + 7;

public:
  int numOfWays(int n)
  {
    long long abc = 6;
    long long aba = 6;

    for (int i = 1; i < n; i++)
    {
      long long new_abc = (abc * 2 + aba * 2) % MOD;
      long long new_aba = (abc * 2 + aba * 3) % MOD;

      abc = new_abc;
      aba = new_aba;
    }

    return (abc + aba) % MOD;
  }
};

int main()
{
  Solution *sol = new Solution;
  sol->numOfWays(1);

  return 0;
}