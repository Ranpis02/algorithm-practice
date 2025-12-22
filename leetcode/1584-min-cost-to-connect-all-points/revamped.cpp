#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    int n = points.size();

    vector<bool> visited(n, false);
    vector<int> dist(n, INT_MAX);

    int pointCnt = 0;
    int ans = 0;

    int cur = 0;
    dist[0] = 0;

    while (pointCnt < n)
    {
      // Select the nearest node.
      int nextNode = -1;
      int minDist = INT_MAX;

      for (int i = 0; i < n; i++)
      {
        if (!visited[i] && dist[i] < minDist)
        {
          nextNode = i;
          minDist = dist[i];
        }
      }

      visited[nextNode] = true;
      pointCnt++;

      ans += minDist;

      // Update the shortest distance to the node.
      for (int i = 0; i < n; i++)
      {
        if (!visited[i])
        {
          int d = abs(points[nextNode][0] - points[i][0]) + abs(points[nextNode][1] - points[i][1]);
          if (d < dist[i])
          {
            dist[i] = d;
          }
        }
      }
    }

    return ans;
  }
};

int main()
{
  return 0;
}