#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  vector<vector<string>> ans;
  vector<int> poss;
  vector<string> tmp;
  string temp;

public:
  vector<vector<string>> solveNQueens(int n)
  {
    temp.assign(n, '.');
    poss.assign(n, 0);

    backtracking(0, 0, 0, 0, n);

    return ans;
  }

  void backtracking(int row, int colMask, int ld, int rd, int n)
  {
    if (row == n)
    {
      tmp.assign(n, temp);
      for (int i = 0; i < poss.size(); i++)
      {
        tmp[i][poss[i]] = 'Q';
      }
      ans.push_back(tmp);

      return;
    }

    int available = ((1 << n) - 1) & (~(colMask | ld | rd));

    while (available)
    {
      int p = available & (-available);

      int colIndex = n - 1 - __builtin_ctz(p);
      poss[row] = colIndex;

      backtracking(row + 1, colMask | p, (ld | p) << 1, (rd | p) >> 1, n);

      available &= (available - 1);
    }
  }
};

int main()
{
  Solution *sol = new Solution;
  sol->solveNQueens(1);

  return 0;
}