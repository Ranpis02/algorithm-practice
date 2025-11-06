#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> vec(n + 1);
    for (int i = 0; i <= n; i++)
    {
      vec[i] = countOnes(i);
    }
    return vec;
  }

private:
  int countOnes(int n)
  {
    int cnt = 0;

    while (n > 0)
    {
      n = n & (n - 1);
      cnt++;
    }

    return cnt;
  }
};

int main()
{
  Solution *s = new Solution;

  int n = 10;

  return 0;
}