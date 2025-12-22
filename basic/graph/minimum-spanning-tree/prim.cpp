#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// first: weight, second: target
using PII = pair<int, int>;

int n, m;
constexpr int INF = 0x3f3f3f3f;

void solve()
{
  priority_queue<PII, vector<PII>, greater<>> pq;
  vector<vector<PII>> adj(n + 1);
  vector<bool> visited(n + 1, false);

  // Input weighted edges for the graph.
  int s, t, v;
  for (int i = 0; i < m; i++)
  {
    cin >> s >> t >> v;

    adj[s].push_back({v, t});
    adj[t].push_back({v, s});
  }

  // Excute the MST program.
  int minDist = 0;
  int pointCnt = 0;
  pq.push({0, 1});

  while (!pq.empty())
  {
    int d = pq.top().second;
    int w = pq.top().first;

    pq.pop();
    if (visited[d])
      continue;

    visited[d] = true;
    minDist += w;
    pointCnt++;

    for (auto &p : adj[d])
    {
      int pd = p.second;
      int pw = p.first;

      if (!visited[pd])
      {
        pq.push(p);
      }
    }
  }

  int ans = (pointCnt == n) ? minDist : -1;
  cout << ans << '\n';
}

int main()
{
  cin >> n >> m;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}