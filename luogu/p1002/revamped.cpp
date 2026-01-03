#include <bits/stdc++.h>

using namespace std;

int dir[8][2] = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};

void solve()
{
  int tx, ty, hx, hy;

  cin >> tx >> ty >> hx >> hy;

  // int dp[20][20] = {0};
  // int ctrl[20][20]
  vector<vector<long long>> dp(tx + 1, vector<long long>(ty + 1, 0));
  vector<vector<bool>> control(tx + 1, vector<bool>(ty + 1, false));

  control[hx][hy] = true;

  for (auto &d : dir)
  {
    int x = hx + d[0];
    int y = hy + d[1];

    if (x >= 0 && y >= 0 && x <= tx && y <= ty)
    {
      control[x][y] = true;
    }
  }

  dp[0][0] = control[0][0] ? 0 : 1;

  for (int i = 0; i <= tx; i++)
  {
    for (int j = 0; j <= ty; j++)
    {
      if (control[i][j])
        continue;

      if (i == 0 && j == 0)
        continue;

      if (i > 0)
        dp[i][j] += dp[i - 1][j];

      if (j > 0)
        dp[i][j] += dp[i][j - 1];
    }
  }

  cout << dp[tx][ty] << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}