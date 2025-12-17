#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();

    vector<vector<int>> adj(n + 1);

    for (auto &edge : edges)
    {
      int s = edge[0], t = edge[1];

      vector<bool> visited(n + 1, false);

      visited[s] = true;
      if (!adj[s].empty() && !adj[t].empty() && hasPath(s, t, adj, visited))
      {
        return edge;
      }

      adj[s].push_back(t);
      adj[t].push_back(s);
    }

    return {};
  }

  bool hasPath(int source, int target, vector<vector<int>> &adj, vector<bool> &visited)
  {
    if (source == target)
      return true;

    for (auto &p : adj[source])
    {
      if (visited[p])
        continue;

      visited[p] = true;
      if (hasPath(p, target, adj, visited))
        return true;
    }

    return false;
  }
};

int main()
{

  return 0;
}