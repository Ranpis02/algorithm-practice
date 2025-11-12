#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    int len = s.size();
    if (len & 1)
      return false;

    stack<char> st;
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}};

    for (char ch : s)
    {
      if (!st.empty() && pairs.count(ch) && pairs[ch] == st.top())
      {
        st.pop();
      }
      else
      {
        st.push(ch);
      }
    }
    if (st.empty())
      return true;
    else
      return false;
  }
};

int main()
{

  return 0;
}