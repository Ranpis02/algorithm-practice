#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          int num = 1;
          grid[i][j] = 0;
          q.push({i, j});

          while (!q.empty())
          {
            int x = q.front().first;
            int y = q.front().second;

            for (auto &d : dir)
            {
              int nextX = x + d[0];
              int nextY = y + d[1];

              if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && grid[nextX][nextY] == 1)
              {
                num++;
                grid[nextX][nextY] = 0;
                q.push({nextX, nextY});
              }
            }
            q.pop();
          }

          ans = max(ans, num);
        }
      }
    }

    return ans;
  }
};

int main()
{
  vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  Solution *sol = new Solution;
  sol->maxAreaOfIsland(grid);
  return 0;
}