#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();
    parent.resize(n + 1);

    iota(parent.begin(), parent.end(), 0);
    rank.assign(n + 1, 1);

    for (auto &edge : edges)
    {
      int s = edge[0], t = edge[1];

      if (unite(s, t))
        return edge;
    }

    return {};
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
      return true;

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

    return false;
  }
};

int main()
{
  return 0;
}