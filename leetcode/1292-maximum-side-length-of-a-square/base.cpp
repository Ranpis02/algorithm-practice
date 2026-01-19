#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold)
  {
    int m = mat.size(), n = mat[0].size();

    vector<vector<long long>> s(m + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        int len = min(i, j) + 1;
        for (int k = len; k > ans; k--)
        {
          if (check(i + 1, j + 1, k, threshold, s))
          {
            ans = k;
            break;
          }
        }
      }
    }

    return ans;
  }

  bool check(int x, int y, int len, int threshold, vector<vector<long long>> &s)
  {
    int sx = x - len;
    int sy = y - len;

    long long sum = s[x][y] - s[x][sy] - s[sx][y] + s[sx][sy];
    return sum <= threshold;
  }
};

int main()
{
  vector<vector<int>> mat = {{2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}};

  Solution *sol = new Solution;
  sol->maxSideLength(mat, 1);

  return 0;
}