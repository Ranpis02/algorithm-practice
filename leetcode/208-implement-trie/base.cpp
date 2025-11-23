#include <iostream>

using namespace std;

struct TrieNode
{
  bool isEnd = false;
  TrieNode *children[26] = {nullptr};

  TrieNode() {}
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode();
  }

  void insert(const string &word)
  {
    TrieNode *node = root;

    for (char ch : word)
    {
      int index = ch - 'a';
      if (!node->children[index])
        node->children[index] = new TrieNode();

      node = node->children[index];
    }
    node->isEnd = true;
  }

  bool search(const string &word)
  {
    TrieNode *node = root;

    for (char ch : word)
    {
      int index = ch - 'a';
      if (!node->children[index])
        return false;

      node = node->children[index];
    }

    return node->isEnd;
  }

  bool startsWith(const string &prefix)
  {
    TrieNode *node = root;

    for (char ch : prefix)
    {
      int index = ch - 'a';
      if (!node->children[index])
        return false;

      node = node->children[index];
    }

    return true;
  }
};

int main()
{

  return 0;
}