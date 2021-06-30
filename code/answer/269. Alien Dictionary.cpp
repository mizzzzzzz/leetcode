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

class Solution
{
public:
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26));
        vector<bool> visited(26);
        string res;
        for (string word : words) {
            for (char c : word) {
                g[c - 'a'][c - 'a'] = true;
            }
        }
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            int mn = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < mn; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    g[words[i][j] - 'a'][words[i + 1][j] - 'a'] = true;
                    break;
                }
            }
            if (j == mn && words[i].size() > words[i + 1].size()) return "";
        }
        for (int i = 0; i < 26; ++i) {
            if (!dfs(g, i, visited, res)) return "";
        }
        return res;
    }
    bool dfs(vector<vector<bool>>& g, int idx, vector<bool>& visited, string& res) {
        if (!g[idx][idx]) return true;
        visited[idx] = true;
        for (int i = 0; i < 26; ++i) {
            if (i == idx || !g[i][idx]) continue;
            if (visited[i]) return false;
            if (!dfs(g, i, visited, res)) return false;
        }
        visited[idx] = false;
        g[idx][idx] = false;
        res += 'a' + idx;
        return true;
    }
};

};

int main()
{
    Solution s;
    {
        vector<vector<int>>input{ {0, 1, 0}, {1, 1, 1}, {0, 1, 0} };
        int target = 1;
        int ans = 4;
        assert(ans == s.numSubmatrixSumTarget(input, target));
    }
    {
        vector<vector<int>>input{ {1, -1}, {-1, 1} };
        int target = 0;
        int ans = 5;
        assert(ans == s.numSubmatrixSumTarget(input, target));
    }
    {
        vector<vector<int>>input{ {904} };
        int target = 0;
        int ans = 0;
        assert(ans == s.numSubmatrixSumTarget(input, target));
    }


    return 0;
}