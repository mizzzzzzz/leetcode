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

// https://leetcode.com/problems/house-robber/
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int steal = 0;
        int notsteal = 0;
        for (int& n : nums) {
            int ls = steal;
            steal = notsteal + n;
            notsteal = std::max(ls, notsteal);
        }
        return std::max(steal, notsteal);
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 1,2,3,1 };
        int ans = 4;
        assert(ans == s.rob(input));
    }
    {
        vector<int> input{ 2,1,1,2 };
        int ans = 4;
        assert(ans == s.rob(input));
    }
    {
        vector<int> input{ 1,2,3,1 };
        int ans = 4;
        assert(ans == s.rob(input));
    }
    {
        vector<int> input{ 2,7,9,3,1 };
        int ans = 12;
        assert(ans == s.rob(input));
    }
    return 0;
}