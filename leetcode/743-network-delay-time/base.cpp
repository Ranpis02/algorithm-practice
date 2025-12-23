#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0X3F3F3F3F;

struct Node
{
  int u, d;

  bool operator>(const Node &other) const
  {
    return d > other.d;
  }
};

class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    // first: end node, second: edge weight
    vector<vector<pair<int, int>>> adj(n + 1);

    // vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INF);
    dist[k] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Input the edges and their weights
    for (auto time : times)
    {
      int u = time[0];
      int v = time[1];
      int w = time[2];

      adj[u].push_back({v, w});
    }

    pq.push({k, 0});

    while (!pq.empty())
    {
      auto [u, d] = pq.top();

      pq.pop();

      // if (visited[u])
      //   continue;

      if (d > dist[u])
        continue;
      // visited[u] = true;

      for (auto &[v, w] : adj[u])
      {
        if ((dist[u] + w) < dist[v])
        {
          dist[v] = dist[u] + w;
          pq.push({v, dist[v]});
        }
      }
    }

    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
      if (dist[i] == INF)
        return -1;
      ans = max(ans, dist[i]);
    }

    return ans;
  }
};

int main()
{
  Solution *sol = new Solution;
  vector<vector<int>> times = {{1, 2, 1}};
  int n = 2;
  int k = 2;

  sol->networkDelayTime(times, n, k);

  return 0;
}