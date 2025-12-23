#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;

/**
 * - v: end node
 * - w: edge weight
 */
struct Edge
{
  int v, w;
};

/**
 * - u: start node
 * - d: the distance from start node to the target node
 */
struct Node
{
  int u, d;

  bool operator>(const Node &other) const
  {
    return d > other.d;
  }
};

vector<int> dijkstra_heap(int start, int n, vector<vector<Edge>> &adj)
{
  if (start >= n || start < 0)
    return {};

  priority_queue<Node, vector<Node>, greater<Node>> pq;

  vector<int> dist(n, INF);
  vector<bool> visited(n, false);

  dist[start] = 0;
  pq.push({start, 0});

  while (!pq.empty())
  {
    // auto [u, d] = pq.top();
    int u = pq.top().u;
    pq.pop();

    if (visited[u])
      continue;

    visited[u] = true;

    for (auto &edge : adj[u])
    {
      auto [v, w] = edge;
      // The condition `!visited[v]` can be omitted.
      if (!visited[v] && (dist[u] + w) < dist[v])
      {
        dist[v] = dist[u] + w;
        pq.push({v, dist[v]});
      }
    }
  }

  return dist;
}

int main()
{

  return 0;
}