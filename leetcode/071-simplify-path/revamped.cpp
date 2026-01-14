#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  string simplifyPath(string path)
  {
    vector<string> segs;

    path.push_back('/');
    string name = "";

    for (char ch : path)
    {
      if (ch == '/')
      {
        if (name == "..")
        {
          if (!segs.empty())
            segs.pop_back();
        }
        else if (!name.empty() && name != ".")
        {
          segs.push_back(name);
        }

        name.clear();
      }
      else
      {
        name += ch;
      }
    }

    if (segs.empty())
      return "/";

    string ans = "";
    for (string &seg : segs)
    {
      ans += '/';
      ans += seg;
    }

    return ans;
  }
};

int main()
{

  return 0;
}