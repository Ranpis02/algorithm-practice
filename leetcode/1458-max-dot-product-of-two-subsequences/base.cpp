#include <bits/stdc++.h>

using namespace std;

class Solution
{
  static constexpr int INF = 0x3F3F3F3F;

public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size(), m = nums2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        // dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1], nums1[i - 1] * nums2[j - 1]});
        dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1], nums1[i - 1] * nums2[j - 1]});
      }
    }

    return dp[n][m];
  }
};

int main()
{
  vector<int> nums1 = {2, 1, -2, 5};
  vector<int> nums2 = {3, 0, -6};

  Solution *sol = new Solution;
  sol->maxDotProduct(nums1, nums2);

  return 0;
}