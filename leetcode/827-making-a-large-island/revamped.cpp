#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_set>

using namespace std;

class Solution
{
private:
  static constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<int> isIsland;

public:
  int largestIsland(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    int isIslandId = 2;
    isIsland.assign(2, 0);
    int maxArea = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          grid[i][j] = isIslandId;
          int currentArea = dfs(grid, i, j, isIslandId);
          maxArea = max(maxArea, currentArea);
          isIsland.push_back(currentArea);
          isIslandId++;
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {
          unordered_set<int> st;
          int t = 1;
          for (auto &d : dir)
          {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 1 && !st.count(grid[x][y]))
            {
              t += isIsland[grid[x][y]];
              st.insert(grid[x][y]);
            }
          }

          maxArea = max(maxArea, t);
        }
      }
    }

    return maxArea;
  }

  int dfs(vector<vector<int>> &grid, int x, int y, int isIslandId)
  {
    int m = grid.size(), n = grid[0].size();
    int area = 1;

    for (auto &d : dir)
    {
      int nextX = x + d[0];
      int nextY = y + d[1];

      if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && grid[nextX][nextY] == 1)
      {
        grid[nextX][nextY] = isIslandId;
        area += dfs(grid, nextX, nextY, isIslandId);
      }
    }

    return area;
  }
};

int main()
{
  vector<vector<int>> grid = {{1, 1},
                              {1, 1}};

  Solution *sol = new Solution;
  sol->largestIsland(grid);

  return 0;
}