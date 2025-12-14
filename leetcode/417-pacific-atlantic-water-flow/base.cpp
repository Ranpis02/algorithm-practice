#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Brute force: traverse each point in the grid, then check if the water flows to both boundaries.
 */
class Solution
{
private:
  static constexpr int dir[4][2] = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1}};

  vector<vector<bool>> visited;

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    int m = heights.size(), n = heights[0].size();

    vector<vector<int>> ans;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        visited.assign(m, vector<bool>(n, false));
        bool flag1 = false, flag2 = false;
        visited[i][j] = true;
        dfs(heights, i, j, flag1, flag2);

        if (flag1 && flag2)
          ans.push_back({i, j});
      }
    }
    return ans;
  }

  void dfs(const vector<vector<int>> &heights, int x, int y, bool &flag1, bool &flag2)
  {
    int m = heights.size(), n = heights[0].size();
    if (x == 0 || y == 0)
    {
      flag1 = true;
    }

    if (x == m - 1 || y == n - 1)
    {
      flag2 = true;
    }

    if (flag1 && flag2)
    {
      return;
    }

    for (auto &d : dir)
    {
      int nextX = x + d[0];
      int nextY = y + d[1];

      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
        continue;

      if (heights[nextX][nextY] <= heights[x][y] && !visited[nextX][nextY])
      {
        visited[nextX][nextY] = true;
        dfs(heights, nextX, nextY, flag1, flag2);
      }
    }
  }
};

int main()
{
  vector<vector<int>> grid = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
  Solution *sol = new Solution;
  sol->pacificAtlantic(grid);

  return 0;
}