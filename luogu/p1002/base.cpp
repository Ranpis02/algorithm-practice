#include <iostream>
#include <vector>

using namespace std;

int dir[8][2] = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};

// int dfs(int x, int y)
// {
//   if (board[x][y] == -1)
//     return 0;
//   if (x == mx && y == my)
//     return 1;
//   if (x > mx || y > my)
//     return 0;

//   int ans = 0;

//   ans += dfs(x + 1, y);
//   ans += dfs(x, y + 1);

//   return ans;
// }

void solve()
{
  int mx, my, bx, by;

  cin >> mx >> my >> bx >> by;

  vector<vector<int>> board(mx + 1, vector<int>(my + 1, 0));
  board[bx][by] = -1;

  vector<vector<long long>> dp(mx + 1, vector<long long>(my + 1, 0));

  dp[0][0] = 1;

  for (auto &d : dir)
  {
    int x = bx + d[0];
    int y = by + d[1];

    if (x >= 0 && y >= 0 && x <= mx && y <= my)
    {
      board[x][y] = -1;
    }

    if (x == 0 && y == 0)
      dp[0][0] = 0;
  }

  for (int i = 1; i <= mx; i++)
  {
    if (board[i][0] == -1)
      dp[i][0] = 0;
    else
    {
      dp[i][0] = dp[i - 1][0];
    }
  }

  for (int i = 1; i <= my; i++)
  {
    if (board[0][i] == -1)
      dp[0][i] = 0;
    else
    {
      dp[0][i] = dp[0][i - 1];
    }
  }

  for (int i = 1; i <= mx; i++)
  {
    for (int j = 1; j <= my; j++)
    {
      if (board[i][j] == -1)
        dp[i][j] = 0;
      else
      {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }

  cout << dp[mx][my] << "\n";
}

int main()
{
  ios::sync_with_stdio(false);

  solve();
  return 0;
}