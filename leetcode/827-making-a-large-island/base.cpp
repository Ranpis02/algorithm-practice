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
  vector<vector<pair<int, shared_ptr<int>>>> mark;
  vector<vector<bool>> visited;

public:
  int largestIsland(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    mark.assign(m, vector<pair<int, shared_ptr<int>>>(n));
    visited.assign(m, vector<bool>(n, false));

    int ans = 0;
    int idx = 1;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] && !visited[i][j])
        {
          visited[i][j] = true;
          auto sp = make_shared<int>(1);
          mark[i][j] = {idx, sp};
          dfs(grid, i, j, idx, sp);
          idx++;
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!grid[i][j])
        {
          int t = 1;
          unordered_set<int> st;
          for (auto &d : dir)
          {
            int x = i + d[0];
            int y = j + d[1];

            if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y] || st.count(mark[x][y].first))
              continue;

            st.insert(mark[x][y].first);
            t += (*mark[x][y].second);
          }

          ans = max(ans, t);
        }
        else
        {
          ans = max(ans, (*mark[i][j].second));
        }
      }
    }
    return ans;
  }

  void dfs(const vector<vector<int>> &grid, int x, int y, int idx, shared_ptr<int> sp)
  {
    int m = grid.size(), n = grid[0].size();

    for (auto &d : dir)
    {
      int nextX = x + d[0];
      int nextY = y + d[1];

      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || visited[nextX][nextY] || !grid[nextX][nextY])
        continue;

      visited[nextX][nextY] = true;
      ++(*sp);
      mark[nextX][nextY] = {idx, sp};
      dfs(grid, nextX, nextY, idx, sp);
    }
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