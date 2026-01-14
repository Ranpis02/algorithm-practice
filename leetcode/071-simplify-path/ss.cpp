#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    stringstream ss(path);

    vector<string> store;
    string seg;
    while (getline(ss, seg, '/'))
    {
      if (seg == "..")
      {
        if (!store.empty())
          store.pop_back();
      }
      else if (!seg.empty() && seg != ".")
      {
        store.push_back(seg);
      }
    }

    if (store.empty())
      return "/";

    string ans = "";

    for (auto &s : store)
    {
      ans += '/';
      ans += s;
    }

    return ans;
  }
};

int main()
{

  return 0;
}