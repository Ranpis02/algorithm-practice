#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool exist(vector<vector<char>> &board, string word)
  {
    int m = board.size(), n = board[0].size();
    int len = word.size();
    if (m * n < len)
      return false;

    unordered_map<char, int> boardStat;
    unordered_map<char, int> wordStat;
    flag = false;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        char ch = board[i][j];
        boardStat[ch]++;
      }
    }

    for (auto &ch : word)
    {
      wordStat[ch]++;

      if (!boardStat.count(ch) || wordStat[ch] > boardStat[ch])
        return false;
    }

    if (boardStat[word.back()] < boardStat[word[0]])
      reverse(word.begin(), word.end());

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == word[0])
        {
          dfs(i, j, 0, word, board);
          if (flag)
            return true;
        }
      }
    }

    return false;
  }

  void dfs(int x, int y, int idx, string &word, vector<vector<char>> &board)
  {
    if (flag || word[idx] != board[x][y])
      return;

    if (idx == word.size() - 1)
    {
      flag = true;
      return;
    }

    char tmp = board[x][y];

    board[x][y] = '\0';

    int m = board.size(), n = board[0].size();
    for (auto &d : dirs)
    {
      int next_x = x + d[0];
      int next_y = y + d[1];

      if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n || board[next_x][next_y] == '\0')
        continue;

      dfs(next_x, next_y, idx + 1, word, board);
    }

    board[x][y] = tmp;
  }

private:
  static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  bool flag = false;
};

int main()
{
  vector<vector<char>> ch = {{'a'}};

  Solution *sol = new Solution;
  string word = "a";

  sol->exist(ch, word);

  return 0;
}