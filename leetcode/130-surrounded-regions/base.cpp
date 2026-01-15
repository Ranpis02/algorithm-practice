#include <bits/stdc++.h>

using namespace std;

// struct PairHash
// {
//   template <class T1, class T2>
//   size_t operator()(const pair<T1, T2> &p) const
//   {
//     auto h1 = hash<T1>{}(p.first);
//     auto h2 = hash<T2>{}(p.second);

//     return h1 ^ (h2 << 1);
//   }
// };

class Solution
{
public:
  void solve(vector<vector<char>> &board)
  {
    int m = board.size(), n = board[0].size();
    if (m <= 2 || n <= 2)
      return;

    for (int i = 0; i < m; i++)
    {
      if (board[i][0] == 'O')
        dfs(i, 0, board);

      if (board[i][n - 1] == 'O')
        dfs(i, n - 1, board);
    }

    for (int i = 0; i < n; i++)
    {
      if (board[0][i] == 'O')
        dfs(0, i, board);

      if (board[m - 1][i] == 'O')
        dfs(m - 1, i, board);
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == '#')
        {
          board[i][j] = 'O';
        }
        else
        {
          board[i][j] = '#';
        }
      }
    }
  }

  void dfs(int x, int y, vector<vector<char>> &board)
  {
    int m = board.size(), n = board[0].size();

    board[x][y] = '#';

    for (auto &dir : dirs)
    {
      int next_x = x + dir[0];
      int next_y = y + dir[1];

      if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && board[next_x][next_y] == 'O')
      {
        dfs(next_x, next_y, board);
      }
    }
  }

private:
  static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

int main()
{

  return 0;
}