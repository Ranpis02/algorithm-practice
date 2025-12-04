#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<int>> ans;
  vector<int> path;

public:
  vector<vector<int>> combine(int n, int k)
  {
    ans.clear();
    path.clear();

    backtracking(1, n, k);

    return ans;
  }

  void backtracking(int startIdx, int n, int k)
  {
    if (path.size() == k)
    {
      ans.push_back(path);
      return;
    }

    // Pruning 1: when i > (n - (k - path.size()) + 1), the remaining numers are not enough to fill the required (k - path.size()) elements.
    for (int i = startIdx; i <= (n - (k - path.size()) + 1); i++)
    {
      path.push_back(i);
      backtracking(i + 1, n, k);
      path.pop_back();
    }
  }
};

int main()
{
  return 0;
}