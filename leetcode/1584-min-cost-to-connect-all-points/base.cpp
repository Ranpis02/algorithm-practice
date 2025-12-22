#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    int n = points.size();
    vector<vector<pair<int, int>>> adj(n);

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

        adj[i].push_back({dist, j});
        adj[j].push_back({dist, i});
      }
    }

    int minDist = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
      int w = pq.top().first;
      int d = pq.top().second;

      pq.pop();
      if (visited[d])
        continue;

      visited[d] = true;
      minDist += w;

      for (auto &p : adj[d])
      {
        int pw = p.first;
        int pd = p.second;

        if (!visited[pd])
        {
          pq.push({pw, pd});
        }
      }
    }

    return minDist;
  }
};

int main()
{
  vector<vector<int>> points = {{3, 12}, {-2, 5}, {-4, 1}};

  Solution *sol = new Solution;
  sol->minCostConnectPoints(points);

  return 0;
}