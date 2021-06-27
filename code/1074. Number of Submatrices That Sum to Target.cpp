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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        int count = 0;
        for (int cl = 0; cl < n; ++cl) {
            for (int cr = cl; cr < n; ++cr) {
                unordered_map<int, int> mp;
                int sum = 0;
                mp[0] = 1;
                for (int r = 0; r < m; ++r) {
                    sum += matrix[r][cr] - (cl > 0 ? matrix[r][cl - 1] : 0);
                    auto it = mp.find(sum - target);
                    if (it != mp.end()) {
                        count += it->second;
                    }
                    mp[sum] += 1;
                }
            }
        }
        return count;
    }
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