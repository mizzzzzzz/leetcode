#include <algorithm>
#include <cassert>
#include <queue>>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

// https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> v;
        for (int i = 0; i < m; i++) {
            v.emplace_back(vector<int>(n));
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    v[i][j] = 1;
                } else {
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
                }
            }
        }
        return v[m - 1][n - 1];
    }

private:
    using pii = pair<int, int>;
    struct entry {
        int count;
        int numPath;
    };

    int bottomUp(int m, int n)
    {
        vector<vector<entry>> v;
        for (int i = 0; i < m; i++) {
            v.emplace_back(vector<entry>(n));
            for (int j = 0; j < n; j++) {
                v[i][j].count = 0;
                if (i + 1 < m) {
                    ++v[i][j].count;
                }
                if (j + 1 < n) {
                    ++v[i][j].count;
                }
            }
        }
        v[m - 1][n - 1].count = 1;
        v[m - 1][n - 1].numPath = 1;

        queue<pii> q;
        q.emplace(m - 1, n - 1);
        while (!q.empty()) {
            const pii& index = q.front();
            entry& e = v[index.first][index.second];
            --e.count;
            if (e.count == 0) {
                if (index.first - 1 >= 0) {
                    q.emplace(index.first - 1, index.second);
                }
                if (index.second - 1 >= 0) {
                    q.emplace(index.first, index.second - 1);
                }
                if (index.first + 1 < m) {
                    e.numPath += v[index.first + 1][index.second].numPath;
                }
                if (index.second + 1 < n) {
                    e.numPath += v[index.first][index.second + 1].numPath;
                }
            }
            q.pop();
        }
        return v[0][0].numPath;
    }
};

int main()
{
    Solution s;
    {
        assert(3 == s.uniquePaths(3, 2));
    }
    {
        assert(28 == s.uniquePaths(3, 7));
    }
    {
        assert(28 == s.uniquePaths(7, 3));
    }
    {
        assert(6 == s.uniquePaths(3, 3));
    }
    {
        assert(193536720 == s.uniquePaths(23, 12));
    }

    return 0;
}