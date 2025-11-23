#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Trie tree
 *
 * - common applicatin scenarios: autocomplete, spell checking, longest prefix matching
 *
 * - pros: fast search and insertion
 * - cons:
 * - cons: high space usgae
 */

/**
 * Trie tree definition
 */
struct TrieNode
{
  /**
   * The children array stores pointers to child node.(only contains 26 lowercase letters 'a' to 'z)
   */
  TrieNode *children[26] = {nullptr};

  /**
   * Marks whether this node represents the end of a word.
   */
  bool isEnd = false;

  /**
   * Void constrcut function
   */
  TrieNode()
  {
  }
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

  /**
   * Insert a word into a Trie
   */
  void insert(string word)
  {
    TrieNode *node = root;
    for (char ch : word)
    {
      int index = ch - 'a';

      // If current node does not exist, create a new node
      if (node->children[index] == nullptr)
      {
        node->children[index] = new TrieNode();
      }

      // Move to the next node
      node = node->children[index];
    }
    // Mark the current node as the end of the word
    node->isEnd = true;
  }

  /**
   * Check whether the word exists in the trie
   */
  bool search(string word)
  {
    TrieNode *node = root;

    for (char ch : word)
    {
      int index = ch - 'a';
      if (node->children[index] == nullptr)
      {
        return false;
      }

      node = node->children[index];
    }

    return node->isEnd;
  }

  bool isStartWith(string prefix)
  {
    TrieNode *node = root;
    for (char ch : prefix)
    {
      int index = ch - 'a';

      if (node->children[index] == nullptr)
        return false;

      node = node->children[index];
    }

    return true;
  }

  /**
   * Destructor: free the allocated memory.
   */
  void deleteTrie(TrieNode *node)
  {
    if (node == nullptr)
      return;
    for (int i = 0; i < 26; i++)
    {
      if (node->children[i] != nullptr)
      {
        deleteTrie(node->children[i]);
      }
    }

    delete node;
  }

  ~Trie()
  {
    deleteTrie(root);
  }
};

int main()
{

  return 0;
}