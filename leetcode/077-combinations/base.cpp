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

    for (int i = startIdx; i <= n; i++)
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