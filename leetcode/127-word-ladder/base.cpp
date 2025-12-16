#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    queue<string> q;
    unordered_set<string> dict(wordList.begin(), wordList.end());

    if (!dict.count(endWord))
      return 0;

    q.push(beginWord);

    int step = 1;
    while (!q.empty())
    {

      queue<string> qCopy;

      while (!q.empty())
      {
        string temp = q.front();
        for (int i = 0; i < temp.size(); i++)
        {
          char originChar = temp[i];
          for (char ch = 'a'; ch <= 'z'; ch++)
          {
            temp[i] = ch;

            if (temp == endWord)
              return step + 1;

            if (dict.count(temp))
            {
              qCopy.push(temp);
              dict.erase(temp);
            }
          }
          temp[i] = originChar;
        }
        q.pop();
      }
      step++;

      // q = qCopy;
      swap(q, qCopy);
    }

    return 0;
  }
};

int main()
{
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> dict = {"hot", "dot", "dog", "lot", "log", "cog"};

  Solution *sol = new Solution;
  sol->ladderLength(beginWord, endWord, dict);

  return 0;
}