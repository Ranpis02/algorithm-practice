#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Context: instead of checking where water flows from each cells, we work backwards from oceans.
 */
class Solution
{
private:
  static constexpr int dir[4][2] = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1}};

public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    int m = heights.size(), n = heights[0].size();

    vector<vector<int>> ans;
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
      pacific[i][0] = true;
      dfs(heights, i, 0, pacific);

      atlantic[i][n - 1] = true;
      dfs(heights, i, n - 1, atlantic);
    }

    for (int i = 0; i < n; i++)
    {
      pacific[0][i] = true;
      dfs(heights, 0, i, pacific);

      atlantic[m - 1][i] = true;
      dfs(heights, m - 1, i, atlantic);
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (pacific[i][j] && atlantic[i][j])
        {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }

  void dfs(const vector<vector<int>> &heights, int x, int y, vector<vector<bool>> &visited)
  {
    int m = heights.size(), n = heights[0].size();

    for (auto &d : dir)
    {
      int nextX = x + d[0];
      int nextY = y + d[1];

      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || visited[nextX][nextY])
        continue;

      if (heights[nextX][nextY] >= heights[x][y])
      {
        visited[nextX][nextY] = true;
        dfs(heights, nextX, nextY, visited);
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