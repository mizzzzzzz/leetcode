#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;
using std::min;
class Solution {
public:
    vector<vector<int>> func(vector<vector<int>>& input)
    {
        int n = input.size();
        int m = input[0].size();

        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (input[i][j] == 0) {
                    res[i][j] = 0;
                } else {
                    if (i > 0) {
                        res[i][j] = min(1LL * res[i][j], 1LL * res[i - 1][j] + 1);
                    }

                    if (j > 0) {
                        res[i][j] = min(1LL * res[i][j], 1LL * res[i][j - 1] + 1);
                    }
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i < n - 1) {
                    res[i][j] = min(1LL * res[i][j], 1LL * res[i + 1][j] + 1);
                }

                if (j < m - 1) {
                    res[i][j] = min(1LL * res[i][j], 1LL * res[i][j + 1] + 1);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> input = { { 1, 1, 1 },{ 1, 1, 1 },{ 1, 0, 1 } };
        vector<vector<int>> ans = { { 3, 2, 3 }, { 2, 1, 2 } , { 1, 0, 1 } };
        assert(ans == s.func(input));
    }
    {
        vector<vector<int>> input = { { 0, 1, 0 },{ 1, 1, 1 },{ 1, 1, 1 } };
        vector<vector<int>> ans = { { 0, 1, 0 },{ 1, 2, 1 },{ 2, 3, 2 } };
        assert(ans == s.func(input));
    }
    {
        vector<vector<int>> input = { { 0, 0, 0 },{ 0, 1, 0 },{ 1, 1, 1 } };
        vector<vector<int>> ans = { { 0, 0, 0 },{ 0, 1, 0 },{ 1, 2, 1 } };
        assert(ans == s.func(input));
    }
    {
        vector<vector<int>> input = {{0, 0, 0},{0, 1, 0},{0, 0, 0}};
        vector<vector<int>> ans = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        assert(ans == s.func(input));
    }
    return 0;
}