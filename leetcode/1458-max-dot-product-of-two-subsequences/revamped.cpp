#include <bits/stdc++.h>

using namespace std;

class Solution
{
  static constexpr int INF = 0x3F3F3F3F;

public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size(), m = nums2.size();

    vector<int> dp(m + 1, -INF);

    for (int i = 1; i <= n; i++)
    {
      int pre_diag = -INF;
      for (int j = 1; j <= m; j++)
      {
        int tmp = dp[j]; // represent the dp[i - 1][j]
        int prod = nums1[i - 1] * nums2[j - 1];

        dp[j] = max({dp[j], dp[j - 1], pre_diag + prod, prod});

        pre_diag = tmp;
      }
    }

    return dp[m];
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