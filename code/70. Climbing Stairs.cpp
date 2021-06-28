#include <algorithm>
#include <cassert>
#include <queue>>
#include <utility>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

// https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> stairs(n + 1, 0);
        stairs[0] = 1;
        stairs[1] = 1;
        for (size_t i = 2; i <= n; ++i) {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }
        return stairs[n];
    }
};

int main()
{
    Solution s;
    {
        assert(2 == s.climbStairs(2));
        assert(3 == s.climbStairs(3));
    }
    return 0;
}