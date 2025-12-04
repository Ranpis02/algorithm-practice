#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
  vector<string> ans;

public:
  vector<string> letterCombinations(string digits)
  {
    unordered_map<int, string> mp;
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";

    int n = digits.size();
    vector<string> store(n);

    for (int i = 0; i < n; i++)
    {
      store[i] = mp[digits[i] - '0'];
    }

    vector<char> combination;
    backtracking(store, combination, n);

    return ans;
  }

  void backtracking(const vector<string> &store, vector<char> &combination, int n)
  {
    int layer = combination.size();
    if (n == layer)
    {
      ans.push_back(string(combination.begin(), combination.end()));
      return;
    }

    for (auto &ch : store[layer])
    {
      combination.push_back(ch);
      backtracking(store, combination, n);
      combination.pop_back();
    }
  }
};

int main()
{
  return 0;
}