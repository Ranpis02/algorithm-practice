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

    int shift = k % n;

    int w = n - shift;
    vector<int> tmp(n);

    int idx = 0;
    for (int i = n - shift; i < n; i++)
    {
      tmp[idx++] = nums[i];
    }

    for (int i = 0; i < n - shift; i++)
    {
      tmp[idx++] = nums[i];
    }

    nums = tmp;
  }
};

int main()
{

  return 0;
}