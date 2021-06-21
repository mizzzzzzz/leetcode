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
    int numIslands(vector<vector<char>>& grid)
    {
        using pii = pair<int, int>;
        int numIslands = 0;
        vector<pii> steps{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        vector<vector<bool>> dp{ grid.size(), vector<bool>(grid[0].size(), false) };
        queue<pii> q;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '0' || dp[i][j] != 0) {
                    continue;
                }
                ++numIslands;
                q.emplace(i, j);
                while (!q.empty()) {
                    pii id = q.front();
                    q.pop();
                    dp[id.first][id.second] = numIslands;
                    for (pii& s : steps) {
                        int nexti = id.first + s.first;
                        int nextj = id.second + s.second;

                        // v1
                        if (nexti >= 0 && nexti < grid.size() && nextj >= 0 && nextj < grid[0].size()) {
                            if (grid[nexti][nextj] == '1' && dp[nexti][nextj] == 0) {
                                q.emplace(nexti, nextj);
                            }
                        }
                        // v2
                        if (nexti >= 0 && nexti < grid.size() && nextj >= 0 && nextj < grid[0].size() && grid[nexti][nextj] == '1' && dp[nexti][nextj] == 0) {
                            q.emplace(nexti, nextj);
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<char>> input {
                {'1', '0', '1', '1', '1'},
                {'1', '0', '1', '0', '1'},
                {'1', '1', '1', '0', '1'},
        };
        int ans = 1;
        assert(ans == s.numIslands(input));
    }
    {
        vector<vector<char>> input {
                {'1', '1', '1'},
                {'0', '1', '0'},
                {'1', '1', '1'}};
        int ans = 1;
        assert(ans == s.numIslands(input));
    }
    {
        vector<vector<char>> input {
                {'1', '1', '1', '1', '0'},
                {'1', '1', '0', '1', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '0', '0', '0'}
        };
        int ans = 1;
        assert(ans == s.numIslands(input));
    }
    {
        vector<vector<char>> input {
                {'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}
        };
        int ans = 3;
        assert(ans == s.numIslands(input));
    }
    return 0;
}