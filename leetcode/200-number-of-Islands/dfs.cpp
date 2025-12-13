#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  vector<vector<bool>> visited;
  vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;

    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visited[i][j] && grid[i][j] == '1')
        {
          ans++;
          dfs(grid, i, j);
        }
      }
    }

    return ans;
  }

  void dfs(const vector<vector<char>> &grid, int x, int y)
  {
    int flag = x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    if (flag && grid[x][y] == '1' && !visited[x][y])
    {
      visited[x][y] = true;

      for (int i = 0; i < dir.size(); i++)
      {
        dfs(grid, x + dir[i].first, y + dir[i].second);
      }
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