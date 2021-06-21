#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        dummy = new TrieNode('*');
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* cur = dummy;
        for (char c : word) {
            int id = toIndex(c);
            if (!cur->next[id]) {
                cur->next[id] = new TrieNode(c);
            }
            cur = cur->next[id];
        }
        cur->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* cur = dummy;
        for (char c : word) {
            int id = toIndex(c);
            if (!cur->next[id]) {
                return false;
            }
            cur = cur->next[id];
        }
        return cur->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* cur = dummy;
        for (char c : prefix) {
            int id = toIndex(c);
            if (!cur->next[id]) {
                return false;
            }
            cur = cur->next[id];
        }
        return true;
    }

private:
    struct TrieNode
    {
        TrieNode(char c) : c(c), isEnd(false)
        {
            memset(next, 0, 26 * sizeof(TrieNode*));
        }
        char c;
        bool isEnd;
        TrieNode* next[26];
    };

    TrieNode* dummy;

    int toIndex(char c)
    {
        return c - 'a';
    }
};

int main()
{
    return 0;
}