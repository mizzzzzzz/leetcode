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
    int characterReplacement(string s, int k) {
        int res = 0, maxCnt = 0, start = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            maxCnt = max(maxCnt, ++counts[s[i] - 'A']);
            while (i - start + 1 - maxCnt > k) {
                --counts[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
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