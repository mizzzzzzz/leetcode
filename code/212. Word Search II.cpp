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

class TrieNode
{
public:
    /** Initialize your data structure here. */
    TrieNode()
    {
        c = '*';
        isEnd = false;
        memset(next, 0, 26 * sizeof(TrieNode*));
    }

    TrieNode(char c) : c(c)
    {
        isEnd = false;
        memset(next, 0, 26 * sizeof(TrieNode*));
    }

    bool isAWord()
    {
        return isEnd;
    }

    string getWord()
    {
        return word;
    }

    void setUsed()
    {
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* cur = this;
        for (char c : word) {
            int id = toIndex(c);
            if (!cur->next[id]) {
                cur->next[id] = new TrieNode(c);
            }
            cur = cur->next[id];
        }
        cur->isEnd = true;
        cur->word = word;
    }

    TrieNode* containKeys(char c)
    {
        if (c == '*') {
            return nullptr;
        }
        return next[toIndex(c)];
    }

private:
    char c;
    bool isEnd;
    TrieNode* next[26];
    string word;

    int toIndex(char c)
    {
        return c - 'a';
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        addWords(words);

        vector<string> result;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (trie.containKeys(board[i][j])){
                    dfs(board, i, j, result, &trie);
                }
            }
        }
        return result;
    }

private:
    TrieNode trie;

    void dfs(vector<vector<char>>& board, int i, int j, vector<string>& result, TrieNode* t)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }
        TrieNode* next = t->containKeys(board[i][j]);
        if (!next) {
            return;
        }
        if (next->isAWord()) {
            result.emplace_back(next->getWord());
            next->setUsed();
        }
        int c = board[i][j];
        board[i][j] = '*';
        dfs(board, i - 1, j, result, next);
        dfs(board, i + 1, j, result, next);
        dfs(board, i, j - 1, result, next);
        dfs(board, i, j + 1, result, next);
        board[i][j] = c;
    }

    void addWords(vector<string>& words)
    {
        for (string& w : words) {
            trie.insert(w);
        }
    }

};

int main()
{
    Solution s;
    
    {
        vector<vector<char>> board = {{'o', 'a', 'b', 'n'}, {'o', 't', 'a', 'e'}, {'a', 'h', 'k', 'r'}, {'a', 'f', 'l', 'v'}};
        vector<string> words = {"oa", "oaa"};
        vector<string> ans = { "oa", "oaa" };
        assert(ans == s.findWords(board, words));
    }
    {
        vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
        vector<string> words = {"oath", "pea", "eat", "rain"};
        vector<string> ans = { "oath", "eat" };
        assert(ans == s.findWords(board, words));
    }
    {
        vector<vector<char>> board = { {'a', 'b'} };
        vector<string> words = { "abcb" };
        vector<string> ans = {};
        assert(ans == s.findWords(board, words));
    }
    return 0;
}