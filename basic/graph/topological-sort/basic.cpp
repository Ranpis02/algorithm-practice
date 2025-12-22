#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve()
{
  vector<vector<int>> adj(n);
  vector<int> indegree(n, 0);

  for (int i = 0; i < m; i++)
  {
    int s, t;
    cin >> s >> t;
    adj[s].push_back(t);
    indegree[t]++;
  }

  queue<int> q;

  for (int i = 0; i < n; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  vector<int> ans;

  while (!q.empty())
  {
    int t = q.front();
    q.pop();

    ans.push_back(t);

    for (auto &p : adj[t])
    {
      indegree[p]--;
      if (indegree[p] == 0)
      {
        q.push(p);
      }
    }
  }

  if (ans.size() == n)
  {
    for (int i = 0; i < n - 1; i++)
      cout << ans[i] << " ";
    cout << ans[n - 1];
  }
  else
  {
    cout << -1;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  solve();

  return 0;
}