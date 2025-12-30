#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
  int v, w;
};

bool spfa(int n, int src, vector<vector<Edge>> &adj)
{
  constexpr int INF = 0x3f3f3f3f;

  vector<int> dist(n, INF);
  dist[src] = 0;

  vector<bool> inQueue(n, false);
  vector<int> cnt(n, 0);

  queue<int> q;
  q.push(src);

  inQueue[src] = true;
  bool hasNegCycle = false;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    inQueue[src] = false;

    for (auto &e : adj[u])
    {
      int v = e.v;
      int w = e.w;

      if (dist[u] != INF && dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;

        if (!inQueue[v])
        {
          q.push(v);
          inQueue[v] = true;

          cnt[v]++;
          if (cnt[v] > n)
          {
            return true;
          }
        }
      }
    }
  }

  return false;
}

int main()
{

  return 0;
}