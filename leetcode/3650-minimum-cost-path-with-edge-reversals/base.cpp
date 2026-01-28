#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
  static constexpr int INF = 0x3f3f3f3f;

  struct Node
  {
    int u, d;

    bool operator>(const Node &other) const
    {
      return d > other.d;
    }
  };

public:
  int minCost(int n, vector<vector<int>> &edges)
  {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);
    vector<vector<pair<int, int>>> graph(n);

    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], d = edge[2];
      graph[u].push_back({v, d});
      graph[v].push_back({u, 2 * d});
    }

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
      auto u = pq.top().u;
      if (u == n - 1)
        break;

      pq.pop();

      if (visited[u])
        continue;

      visited[u] = true;

      for (auto &g : graph[u])
      {
        auto [v, w] = g;

        if (dist[u] + w < dist[v])
        {
          dist[v] = dist[u] + w;
          pq.push({v, dist[v]});
        }
      }
    }

    return dist[n - 1] == INF ? -1 : dist[n - 1];
  }
};

int main()
{

  return 0;
}