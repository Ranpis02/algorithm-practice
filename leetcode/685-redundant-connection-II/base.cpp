#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

/**
 * In a directed tree, adding an extra edge can result in three scenaries that violate the tree structure.
 *
 * 1. In-degree of 2: remove the most recently added edge pointing to it.
 * 2. Existence of a cycle: remove the last edge that completes the cycle.
 * 3. Both in-degree of 2 and a cycle: remove the parent-edge the completes the cycle.
 *
 */
class DSU
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  DSU(int size) : parent(size), rank(size, 1)
  {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x)
  {
    if (x == parent[x])
      return x;

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

class Solution
{
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();
    DSU *dsu = new DSU(n + 1);
    vector<int> ancestor(n + 1);
    iota(ancestor.begin(), ancestor.end(), 0);

    int conflict = -1, cycle = -1;
    for (int i = 0; i < n; i++)
    {
      int s = edges[i][0], t = edges[i][1];

      if (ancestor[t] != t)
      {
        conflict = i;
        break;
      }

      ancestor[t] = s;
    }

    for (int i = 0; i < n; i++)
    {
      int s = edges[i][0], t = edges[i][1];

      if (i == conflict)
        continue;

      if (!dsu->unite(s, t))
      {
        cycle = i;
      }
    }

    delete dsu;

    if (conflict >= 0)
    {
      auto edge = edges[conflict];
      if (cycle >= 0)
      {
        return {ancestor[edge[1]], edge[1]};
      }
      else
      {
        return edge;
      }
    }

    return edges[cycle];
  }
};

int main()
{
  Solution *sol = new Solution;
  vector<vector<int>> edges = {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
  sol->findRedundantDirectedConnection(edges);

  return 0;
}