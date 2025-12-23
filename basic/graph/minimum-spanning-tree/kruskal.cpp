#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/**
 * - n: the number of points
 * - m: the number of edges
 */
int n, m;

struct Edge
{
  /**
   * - u: starting point
   * - v: ending point
   * - w: edge weight
   */
  int u, v, w;

  bool operator<(const Edge &other) const
  {
    return w < other.w;
  }
};

class DSU
{
public:
  DSU(int n_) : parent(n_), rank(n_, 1)
  {
    iota(parent.begin(), parent.end(), 0);
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
    else if (rank[rootX > rank[rootY]])
    {
      parent[rootY] = rootX;
    }
    else
    {
      parent[rootX] = rootY;
    }

    return true;
  }

private:
  vector<int> parent;
  vector<int> rank;
};

void kruskal()
{
  vector<Edge> edges;
  DSU *dsu = new DSU(n + 1);

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  sort(edges.begin(), edges.end());

  int minDist = 0;
  int edgeCnt = 0;

  for (int i = 0; i < m; i++)
  {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;

    if (dsu->unite(u, v))
    {
      minDist += w;
      edgeCnt++;
    }
  }

  if (edgeCnt == (n - 1))
  {
    cout << minDist << endl;
  }
  else
  {
    cout << -1 << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<Edge> edges;

  cin >> n >> m;
  kruskal();

  return 0;
}