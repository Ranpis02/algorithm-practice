#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    deque<pair<int, int>> q;
    q.push_back({-1, 0});

    int ans = INT_MIN;
    int acc = 0;

    int n = nums.size();

    for (int i = 0; i < 2 * n; i++)
    {
      acc += nums[i % n];

      while (!q.empty() && q.front().first < (i - n))
        q.pop_front();

      if (!q.empty())
        ans = max(acc - q.front().second, ans);

      while (!q.empty() && q.back().second >= acc)
        q.pop_back();

      q.push_back({i, acc});
    }

    return ans;
  }
};

int main()
{
  vector<int> nums = {-3, -2, -3};
  Solution *sol = new Solution;
  sol->maxSubarraySumCircular(nums);

  return 0;
}