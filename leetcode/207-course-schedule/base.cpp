#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    int n = numCourses;
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);

    for (auto &req : prerequisites)
    {
      int s = req[1];
      int t = req[0];
      indegree[t]++;
      adj[s].push_back(t);
    }

    queue<int> q;
    // vector<int> ans;
    int pointCnt = 0;

    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    while (!q.empty())
    {
      int t = q.front();

      q.pop();
      pointCnt++;

      for (auto &p : adj[t])
      {
        indegree[p]--;
        if (indegree[p] == 0)
          q.push(p);
      }
    }

    return pointCnt == n;
  }
};

int main()
{
  return 0;
}