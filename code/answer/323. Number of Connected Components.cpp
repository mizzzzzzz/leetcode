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
    int countComponents(int n, vector<pair<int, int> >& edges) {
        int res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (auto a : edges) {
            int x = find(root, a.first), y = find(root, a.second);
            if (x != y) {
                --res;
                root[y] = x;
            }
        }
        return res;
    }
    int find(vector<int> &root, int i) {
        while (root[i] != i) i = root[i];
        return i;
    }
    
    ///////////
    
        int countComponents(int n, vector<pair<int, int> >& edges) {
        int res = 0;
        vector<vector<int> > g(n);
        vector<bool> v(n, false);
        for (auto a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                ++res;
                dfs(g, v, i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int> > &g, vector<bool> &v, int i) {
        if (v[i]) return;
        v[i] = true;
        for (int j = 0; j < g[i].size(); ++j) {
            dfs(g, v, g[i][j]);
        }
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