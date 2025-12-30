#include <iostream>
#include <vector>

using namespace std;

/**
 * - u: start point
 * - v: end point
 * - w: edge weight
 */
struct Edge
{
  int u, v, w;
};

/**
 * @brief Calculates the shortest path distance from the source node 0 to destination node v - 1.
 *
 * @param V The total number of vectices int the graph.
 * @param E The total number o edges int the graph.
 * @param edges A reference to a vector of Edge structures representing the graph's connections.
 */
void bellmanford(int V, int E, vector<Edge> &edges)
{

  constexpr int INF = 0x3f3f3f3f;

  vector<int> dist(V, INF);
  dist[0] = 0;

  for (int i = 0; i < V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = edges[j].u;
      int v = edges[j].v;
      int w = edges[j].w;

      if (dist[u] != INF && dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
      }
    }
  }

  // Check if the negative cycle exists.
  bool hasNegCycle = false;
  for (int i = 0; i < E; i++)
  {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;

    if (dist[u] != INF && dist[u] + w < dist[v])
    {
      dist[v] = dist[u] + w;
      hasNegCycle = true;
      break;
    }
  }
};

int main()
{

  return 0;
}