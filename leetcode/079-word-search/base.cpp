#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  bool exist(vector<vector<char>> &board, string word)
  {
    int m = board.size(), n = board[0].size();

    flag = false;
    visited.assign(m, vector<bool>(n, false));

    vector<pair<int, int>> startPoints;
    unordered_map<char, int> boardStat;
    unordered_map<char, int> wordStat;

    int startCh = word[0];

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        char ch = board[i][j];

        if (ch == startCh)
        {
          startPoints.push_back({i, j});
        }

        boardStat[ch]++;
      }
    }

    for (auto &ch : word)
    {
      wordStat[ch]++;

      if (!boardStat.count(ch) || wordStat[ch] > boardStat[ch])
        return false;
    }

    for (auto &[x, y] : startPoints)
    {

      dfs(x, y, 0, word, board);
      if (flag)
        return true;
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

    visited[x][y] = true;

    int m = board.size(), n = board[0].size();
    for (auto &d : dirs)
    {
      int next_x = x + d[0];
      int next_y = y + d[1];

      if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n || visited[next_x][next_y])
        continue;

      visited[next_x][next_y] = true;
      dfs(next_x, next_y, idx + 1, word, board);
      visited[next_x][next_y] = false;
    }

    visited[x][y] = false;
  }

private:
  static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  vector<vector<bool>> visited;
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