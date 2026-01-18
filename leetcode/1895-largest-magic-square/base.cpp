#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int largestMagicSquare(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    prefixRow.assign(m, vector<int>(n + 1, 0));
    prefixColumn.assign(n, vector<int>(m + 1, 0));

    for (int i = 0; i < m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        prefixRow[i][j] = prefixRow[i][j - 1] + grid[i][j - 1];
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        prefixColumn[i][j] = prefixColumn[i][j - 1] + grid[j - 1][i];
      }
    }

    int ans = 1;
    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j < n; j++)
      {
        int maxLen = min(i, j) + 1;

        for (int k = maxLen; k > ans; k--)
        {
          if (check(grid, i, j, k))
          {
            ans = max(k, ans);
            break;
          }
        }
      }
    }

    return ans;
  }

  bool check(vector<vector<int>> &grid, int x, int y, int len)
  {
    int t_x = x - len + 1;
    int t_y = y - len + 1;

    int main_d = 0;
    int second_d = 0;

    for (int i = 0; i < len; i++)
    {
      main_d += grid[x - i][y - i];
      second_d += grid[x - i][t_y + i];
    }

    if (main_d != second_d)
      return false;

    for (int i = 0; i < len; i++)
    {
      int row_acc = prefixRow[x - i][y + 1] - prefixRow[x - i][t_y];
      int col_acc = prefixColumn[y - i][x + 1] - prefixColumn[y - i][t_x];

      if (main_d != row_acc || main_d != col_acc)
        return false;
    }

    return true;
  }

private:
  vector<vector<int>> prefixRow;
  vector<vector<int>> prefixColumn;
};

int main()
{
  vector<vector<int>> grid = {{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};

  Solution *sol = new Solution;
  sol->largestMagicSquare(grid);

  return 0;
}