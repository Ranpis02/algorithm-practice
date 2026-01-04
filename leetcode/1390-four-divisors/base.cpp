#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int sumFourDivisors(vector<int> &nums)
  {
    unordered_map<int, int> mp;

    int n = nums.size();
    int ans = 0;

    for (int num : nums)
    {
      if (!mp.count(num))
      {
        int total = getDivisorsSum(num);
        mp[num] = total;
      }

      ans += mp[num];
    }

    return ans;
  }

  int getDivisorsSum(int n)
  {
    vector<int> divisors;

    for (int i = 1; i <= n; i++)
    {
      if (divisors.size() > 4)
        return 0;
      if (n % i == 0)
      {
        divisors.push_back(i);
      }
    }

    return divisors.size() == 4 ? accumulate(divisors.begin(), divisors.end(), 0) : 0;
  }
};

int main()
{

  return 0;
}