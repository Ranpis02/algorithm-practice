#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
  {
    if (source == destination)
      return true;

    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    rank.assign(n, 1);

    for (auto &edge : edges)
    {
      unite(edge[0], edge[1]);

      // Early Stop: check if the source and destination are connected after each union.
      if (find(source) == find(destination))
        return true;
    }

    return false;
  }

  int find(int x)
  {
    if (x == parent[x])
    {
      return x;
    }

    return (parent[x] = find(parent[x]));
  }

  void unite(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
      return;

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
  }
};

int main()
{
  return 0;
}