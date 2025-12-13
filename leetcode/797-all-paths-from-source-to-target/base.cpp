#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;
  vector<int> path;

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    int n = graph.size();
    dfs(graph, 0, n - 1);

    return ans;
  }

  void dfs(const vector<vector<int>> &graph, int start, int target)
  {
    path.push_back(start);

    if (start == target)
    {
      ans.push_back(path);
    }
    else
    {
      for (int nextNode : graph[start])
      {
        dfs(graph, nextNode, target);
      }
    }

    path.pop_back();
  }
};
int main()
{

  return 0;
}