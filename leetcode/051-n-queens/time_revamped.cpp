#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  vector<vector<string>> ans;
  vector<int> poss;

  // Auxiliary container used to check whether a position is occupied.
  vector<char> cols;
  vector<char> mainDiag;
  vector<char> secondDiag;

public:
  vector<vector<string>> solveNQueens(int n)
  {
    ans.clear();
    poss.clear();

    cols.assign(n, 0);
    mainDiag.assign(2 * n, 0);
    secondDiag.assign(2 * n, 0);

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
      if (cols[i] || mainDiag[row - i + n] || secondDiag[i + row])
        continue;

      cols[i] = 1;
      mainDiag[row - i + n] = 1;
      secondDiag[i + row] = 1;

      poss.push_back(i);
      backtracking(row + 1, n);
      poss.pop_back();

      secondDiag[i + row] = 0;
      mainDiag[row - i + n] = 0;
      cols[i] = 0;
    }
  }

  // bool check(int row, int col)
  // {
  //   for (int i = 0; i < poss.size(); i++)
  //   {
  //     if (col == poss[i] || (abs(row - i) == abs(col - poss[i])))
  //       return false;
  //   }

  //   return true;
  // }
};

int main()
{
  return 0;
}