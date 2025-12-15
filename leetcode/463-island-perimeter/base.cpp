#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  static constexpr int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          grid[i][j] = -1;
          return dfs(grid, i, j);
        }
      }
    }

    return 0;
  }

  int dfs(vector<vector<int>> &grid, int x, int y)
  {
    int m = grid.size(), n = grid[0].size();
    int perimeter = 0;

    for (auto &d : dir)
    {
      int nextX = x + d[0];
      int nextY = y + d[1];

      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || grid[nextX][nextY] == 0)
      {
        perimeter++;
        continue;
      }

      if (grid[nextX][nextY] == 1)
      {
        grid[nextX][nextY] = -1;
        perimeter += dfs(grid, nextX, nextY);
      }
    }

    return perimeter;
  }
};

int main()
{
  vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  Solution *sol = new Solution;
  sol->islandPerimeter(grid);

  return 0;
}