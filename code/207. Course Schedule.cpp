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

// https://leetcode.com/problems/course-schedule/
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].emplace_back(p[0]);
            ++indeg[p[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.emplace(i);
            }
        }

        int n = numCourses;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            --n;
            for (int j : adj[i]) {
                --indeg[j];
                if (indeg[j] == 0) {
                    q.emplace(j);
                }
            }
        }
        return n == 0;
    }
};

int main()
{
    Solution s;
    {
        int numCoureses = 2;
        vector<vector<int>> input{ {1, 0} };
        bool ans = true;
        assert(ans == s.canFinish(numCoureses, input));
    }
    {
        int numCoureses = 2;
        vector<vector<int>> input{ {1, 0}, {0, 1} };
        bool ans = false;
        assert(ans == s.canFinish(numCoureses, input));
    }
    return 0;
}