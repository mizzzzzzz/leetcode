#include <algorithm>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <queue>
using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::pair;
using std::priority_queue;
static int R = 0;
static int C = 0;

class Solution
{
public:
    class pii
    {
    public:
        pii(int i, int j, int step) : i(i), j(j), step(step) {};
        int i;
        int j;
        int step;

        int dist() const
        {
            return step + std::min(i, R - i) + std::min(j, C - j);
        }

        bool operator < (const pii& rhs) const
        {
            return dist() < rhs.dist();
        }
    };
    bool isBorderPos(int i, int j, int r, int c)
    {
        return i == 0 || i == r - 1 || j == 0 || j == c - 1;
    }

    bool validPos(int i, int j, int r, int c)
    {
        return i >= 0 && i < r&& j >= 0 && j < c;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        static vector<pair<int, int>> steps{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };


        int ans = INT_MAX;

        size_t r = maze.size();
        size_t c = maze[0].size();
        R = r;
        C = c;
        vector<vector<int>> visited{ r, vector<int>(c, INT_MAX) };
        priority_queue<pii> q;
        q.emplace(entrance[0], entrance[1], 0);
        while (!q.empty()) {
            pii id = q.top();
            q.pop();
            if (isBorderPos(id.i, id.j, r, c) && (id.i != entrance[0] || id.j != entrance[1]) && maze[id.i][id.j] == '.') {
                if (ans > id.step) {
                    ans = id.step;
                }
                continue;
            }
            for (auto& s : steps) {
                int newi = id.i + s.first;
                int newj = id.j + s.second;
                if (validPos(newi, newj, r, c) && maze[newi][newj] == '.' && visited[newi][newj] > id.step + 1 && id.step + 1 < ans) {
                    visited[newi][newj] = id.step + 1;
                    q.emplace(newi, newj, id.step + 1);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution s;


    {
        vector<vector<char>> input {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
        vector<int> entrance = { 1, 0 };
        assert(2 == s.nearestExit(input, entrance));
    }
    {
        vector<vector<char>> input {{'.', '+'}};
        vector<int> entrance = { 0, 0 };
        assert(-1 == s.nearestExit(input, entrance));
    }
    {
        vector<vector<char>> input{ {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'} };
        vector<int> entrance = { 1, 2 };
        assert(1 == s.nearestExit(input, entrance));
    }
    return 0;
}