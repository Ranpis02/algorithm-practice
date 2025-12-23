#include <iostream>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
/**
 * - n: number of nodes
 * - start: start node
 * - graph: adjacency matrix
 */
vector<int> dijkstra_naive(int n, int start, const vector<vector<int>> &graph)
{
  vector<bool> visited(n, false);
  vector<int> dist(n, INF);

  dist[start] = 0;
  for (int i = 0; i < n; i++)
  {
    // Find the unvisited node with the smallest distance.
    int u = -1;

    for (int j = 0; j < n; j++)
    {
      if (!visited[j] && (u == -1 || dist[j] < dist[u]))
      {
        u = j;
      }
    }

    if (u == -1 || dist[u] == INF)
      break;

    visited[u] = true;

    // Update the distances of nodes reachable from the current node.
    for (int v = 0; v < n; v++)
    {
      if (graph[u][v] != INF)
      {
        if ((dist[u] + graph[u][v]) < dist[v])
          dist[v] = dist[u] + graph[u][v];
      }
    }
  }
  return dist;
}

int main()
{

  return 0;
}