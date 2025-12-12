#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    stringstream ss(s);

    string word;
    vector<string> words;

    while (ss >> word)
    {
      words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string ans = "";

    for (string w : words)
    {
      ans += w;
      ans += " ";
    }

    ans.pop_back();
    return ans;
  }
};

int main()
{
  return 0;
}