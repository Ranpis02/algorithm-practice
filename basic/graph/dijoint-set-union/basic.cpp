#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * @brief Disjoint set union with Path Compresion and Union by rank.
 */
class DSU
{
private:
  vector<int> parent; // Stores the parent node of each element
  vector<int> rank;   // Approximate tree height

public:
  DSU(int n) : parent(n), rank(n, 1)
  {
    iota(parent.begin(), parent.end(), 0);
  }

  /**
   * @brief Finds the root of the set containing element x.
   */
  int find(int x)
  {
    if (x == parent[x])
    {
      return x;
    }
    else
    {
      // Applies path compression while finding the father.
      return parent[x] = find(parent[x]);
    }
  }

  /**
   * @brief Unites the sets containing elements x and y.
   */
  void unite(int x, int y)
  {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
      if (rank[rootX] > rank[rootY])
      {
        parent[rootY] = rootX;
      }
      else if (rank[rootX] < rank[rootY])
      {
        parent[rootX] = rootY;
      }
      else
      {
        parent[rootX] = rootY;
        rank[rootY]++;
      }
    }
  }

  /**
   * @brief Check if the two elements x and y belong to the same set.
   */
  bool connected(int x, int y)
  {
    return find(x) == find(y);
  }
};

int main()
{
  return 0;
}