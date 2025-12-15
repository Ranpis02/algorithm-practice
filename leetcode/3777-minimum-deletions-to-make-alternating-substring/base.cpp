#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BIT
{
private:
  vector<int> tree;
  int size;

public:
  BIT(int size) : tree(size + 1, 0), size(size) {}

  int lowbit(int x)
  {
    return x & (-x);
  }

  void update(int index, int delta)
  {
    for (int i = index; i <= size; i += lowbit(i))
    {
      tree[i] += delta;
    }
  }

  int query(int index)
  {
    int ans = 0;
    for (int i = index; i > 0; i -= lowbit(i))
    {
      ans += tree[i];
    }

    return ans;
  }

  int queryRange(int start, int end)
  {
    return query(end) - query(start - 1);
  }
};

class Solution
{
public:
  vector<int> minDeletions(string s, vector<vector<int>> &queries)
  {
    int n = s.size();
    BIT *bt = new BIT(n);
    vector<int> ans;

    for (int i = 0; i < n - 1; i++)
    {
      if (s[i] == s[i + 1])
        bt->update(i + 1, 1);
    }

    for (auto &query : queries)
    {
      if (query[0] == 1)
      {
        int idx = query[1];
        if (idx > 0)
        {
          if (s[idx] == s[idx - 1])
          {
            bt->update(idx, -1);
          }
          else
          {
            bt->update(idx, 1);
          }
        }

        if ((idx + 1) < n)
        {
          if (s[idx] == s[idx + 1])
          {
            bt->update(idx + 1, -1);
          }
          else
          {
            bt->update(idx + 1, 1);
          }
        }

        s[idx] == 'A' ? s[idx] = 'B' : s[idx] = 'A';
      }
      else
      {
        int l = query[1], r = query[2];

        int t = bt->queryRange(l + 1, r);
        ans.push_back(t);
      }
    }

    delete bt;

    return ans;
  }
};

int main()
{
  string s = "BABA";
  vector<vector<int>> queries = {{2, 0, 3}, {1, 1}, {2, 1, 3}};
  Solution *sol = new Solution;
  sol->minDeletions(s, queries);

  return 0;
}