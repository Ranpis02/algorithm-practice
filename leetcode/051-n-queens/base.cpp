#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  vector<vector<string>> ans;
  vector<int> poss;

public:
  vector<vector<string>> solveNQueens(int n)
  {
    ans.clear();
    poss.clear();

    backtracking(0, n);

    return ans;
  }

  void backtracking(int row, int n)
  {
    if (row == n)
    {
      vector<string> tmp(n, string(n, '.'));
      for (int i = 0; i < poss.size(); i++)
      {
        tmp[i][poss[i]] = 'Q';
      }
      ans.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
    {
      if (!check(row, i))
        continue;

      poss.push_back(i);
      backtracking(row + 1, n);
      poss.pop_back();
    }
  }

  bool check(int row, int col)
  {
    for (int i = 0; i < poss.size(); i++)
    {
      if (col == poss[i] || (abs(row - i) == abs(col - poss[i])))
        return false;
    }

    return true;
  }
};

int main()
{
  return 0;
}