#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::queue;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// https://leetcode.com/problems/number-of-1-bits/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        uint32_t bit = 1;
        for (int i = 0; i < 32; ++i) {
            if ((n & bit) != 0) {
                ++ans;
            }
            bit <<= 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        uint32_t input = 0b00000000000000000000000000001011;
        int ans = 3;
        assert(ans == s.hammingWeight(input));
    }
    {
        uint32_t input = 0b00000000000000000000000010000000;
        int ans = 1;
        assert(ans == s.hammingWeight(input));
    }
    {
        uint32_t input = 0b11111111111111111111111111111101;
        int ans = 31;
        assert(ans == s.hammingWeight(input));
    }
    return 0;
}