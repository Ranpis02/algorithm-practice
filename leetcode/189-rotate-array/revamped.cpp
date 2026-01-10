#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 1 || n == 0 || k == 0)
      return;

    k %= n;

    reverse(nums.begin(), nums.end());

    reverse(nums.begin(), nums.begin() + k);

    reverse(nums.begin() + k, nums.end());
  }
};

int main()
{

  return 0;
}