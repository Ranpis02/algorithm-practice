#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  static constexpr int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == '1')
        {
          ans++;
          dfs(grid, i, j);
        }
      }
    }

    return ans;
  }

  void dfs(vector<vector<char>> &grid, int x, int y)
  {
    grid[x][y] = '0';
    for (auto &d : dir)
    {
      int nextX = x + d[0];
      int nextY = y + d[1];
      int flag = nextX >= 0 && nextX < grid.size() && nextY >= 0 && nextY < grid[0].size();
      if (flag && grid[nextX][nextY] == '1')
        dfs(grid, nextX, nextY);
    }
  }
};

int main()
{
  vector<vector<char>> grid = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}};

  Solution *sol = new Solution;
  sol->numIslands(grid);

  return 0;
}