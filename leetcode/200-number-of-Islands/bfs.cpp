#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
  static constexpr int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '1')
        {
          ans++;

          grid[i][j] = '0';
          q.push({i, j});

          while (!q.empty())
          {
            int x = q.front().first;
            int y = q.front().second;

            for (auto &d : dir)
            {
              int nextX = x + d[0];
              int nextY = y + d[1];

              if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && grid[nextX][nextY] == '1')
              {
                // Critical: Mark the node as visited immediately to avoid duplicate entries in the queue.
                grid[nextX][nextY] = '0';
                q.push({nextX, nextY});
              }
            }
            q.pop();
          }
        }
      }
    }

    return ans;
  }
};

int main()
{
  return 0;
}