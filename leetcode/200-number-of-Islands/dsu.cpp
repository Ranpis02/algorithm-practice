#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution
{
private:
  static constexpr int dir[2][2] = {{-1, 0}, {0, -1}};

  vector<int> parent;
  vector<int> rank;
  int cnt = 0;

public:
  int numIslands(vector<vector<char>> &grid)
  {
    if (grid.empty() || grid[0].empty())
      return 0;

    int m = grid.size(), n = grid[0].size();

    parent.assign(m * n, -1);

    rank.assign(m * n, -1);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '1')
        {
          int pos = i * n + j;
          parent[pos] = pos;
          rank[pos] = 1;
          cnt++;

          for (auto &d : dir)
          {
            int nextX = i + d[0];
            int nextY = j + d[1];

            if (nextX >= 0 && nextY >= 0 && grid[nextX][nextY] == '1')
            {
              int neighbor = nextX * n + nextY;
              bool isUnited = unite(pos, neighbor);
              if (isUnited)
                cnt--;
            }
          }
        }
      }
    }

    return cnt;
  }

  int find(int x)
  {
    if (x == parent[x])
    {
      return x;
    }

    return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
      return false;

    if (rank[rootX] < rank[rootY])
    {
      parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY])
    {
      parent[rootY] = rootX;
    }
    else
    {
      parent[rootX] = rootY;
      rank[rootY]++;
    }

    return true;
  }
};

int main()
{
  vector<vector<char>> islands = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'}};

  Solution *sol = new Solution;
  sol->numIslands(islands);

  return 0;
}