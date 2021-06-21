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

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        uint32_t bit = 1;
        for (int i = 0; i < 32; ++i) {
            ans <<= 1;
            if ((n & bit) != 0) {
                ans += 1;
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
        uint32_t input = 0b00000010100101000001111010011100;
        uint32_t ans = 0b00111001011110000010100101000000;
        assert(ans == s.reverseBits(input));
    }
    {
        uint32_t input = 0b00000010100101000001111010011100;
        uint32_t ans = 0b00111001011110000010100101000000;
        assert(ans == s.reverseBits(input));
    }
    return 0;
}