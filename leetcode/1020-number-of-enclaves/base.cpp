#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
  static constexpr int dir[4][2] = {{1, 0},
                                    {-1, 0},
                                    {0, 1},
                                    {0, -1}};

public:
  int numEnclaves(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
      if (grid[i][0])
      {
        bfs(grid, i, 0);
      }

      if (grid[i][n - 1])
      {
        bfs(grid, i, n - 1);
      }
    }

    for (int i = 0; i < n; i++)
    {
      if (grid[0][i])
      {
        bfs(grid, 0, i);
      }

      if (grid[m - 1][i])
      {
        bfs(grid, m - 1, i);
      }
    }

    // for (int i = 1; i < m - 1; i++)
    // {
    //   for (int j = 1; j < n - 1; j++)
    //   {
    //     if (grid[i][j])
    //     {
    //       int num = bfs(grid, i, j);
    //       ans += n;
    //     }
    //   }
    // }

    for (int i = 1; i < m - 1; i++)
    {
      for (int j = 1; j < n - 1; j++)
      {
        if (grid[i][j])
          ans++;
      }
    }
    return ans;
  }

  void bfs(vector<vector<int>> &grid, int x, int y)
  {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;

    // int num = 1;
    grid[x][y] = 0;
    q.push({x, y});

    while (!q.empty())
    {
      int x = q.front().first;
      int y = q.front().second;

      for (auto &d : dir)
      {
        int nextX = x + d[0];
        int nextY = y + d[1];

        if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && grid[nextX][nextY])
        {
          // num++;
          grid[nextX][nextY] = 0;
          q.push({nextX, nextY});
        }
      }

      q.pop();
    }

    // return num;
  };
};

int main()
{
  vector<vector<int>> grid =
      {
          {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
          {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
          {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
          {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
          {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
          {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
          {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
          {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
          {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
          {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};

  Solution *sol = new Solution;
  sol->numEnclaves(grid);

  return 0;
}