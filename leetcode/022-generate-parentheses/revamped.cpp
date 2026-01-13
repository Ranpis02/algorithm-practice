#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    string path;

    dfs(0, 0, ans, path, n);

    return ans;
  }

  void dfs(int open, int close, vector<string> &ans, string &path, int n)
  {
    if (path.size() == 2 * n)
    {
      ans.push_back(path);

      return;
    }

    if (open < n)
    {
      path.push_back('(');

      dfs(open + 1, close, ans, path, n);

      path.pop_back();
    }

    if (close < open)
    {
      path.push_back(')');

      dfs(open, close + 1, ans, path, n);

      path.pop_back();
    }
  }
};

int main()
{

  return 0;
}