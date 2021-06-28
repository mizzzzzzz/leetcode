#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using std::string;
using std::queue;
using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/word-search/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        for (auto& row : board) {
            for (char c : row) {
                ++boardMap[c];
            }
        }
        for (char c : word) {
            ++wordMap[c];
        }
        for (auto& entry : wordMap) {
            auto it = boardMap.find(entry.first);
            if (it == boardMap.end() || entry.second > it->second) {
                return false;
            }
        }
        visisted = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (exist(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word, int i, int j, int w)
    {
        if (w == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        if (visisted[i][j]) {
            return false;
        }
        if (board[i][j] != word[w]) {
            return false;
        }
        if (boardMap[word[w]] <= 0) {
            return false;
        }
        --boardMap[word[w]];
        visisted[i][j] = true;
        if (exist(board, word, i + 1, j, w + 1) || exist(board, word, i - 1, j, w + 1) ||
                exist(board, word, i, j + 1, w + 1) || exist(board, word, i, j - 1, w + 1)) {
            return true;
        }
        visisted[i][j] = false;
        ++boardMap[word[w]];
        return false;
    }


private:
    vector<vector<bool>> visisted;
    unordered_map<char, int> boardMap;
    unordered_map<char, int> wordMap;
};

int main()
{
    Solution s;
    {
        vector<vector<char>> input {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        string word{"ABCCED"};
        bool ans = true;
        assert(ans == s.exist(input, word));
    }
    {
        vector<vector<char>> input {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        string word{"SEE"};
        bool ans = true;
        assert(ans == s.exist(input, word));
    }
    {
        vector<vector<char>> input {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        string word{"ABCB"};
        bool ans = false;
        assert(ans == s.exist(input, word));
    }

    return 0;
}