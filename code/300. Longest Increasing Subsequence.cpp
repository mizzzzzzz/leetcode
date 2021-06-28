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

// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int ans = 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (cur < dp[j]) {
                        cur = dp[j];
                    }
                }
            }
            dp[i] = cur + 1;
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 1, 3, 6, 7, 9, 4, 10, 5, 6 };
        int ans = 6;
        assert(ans == s.lengthOfLIS(input));
    }
    {
        vector<int> input{ 10,9,2,5,3,7,101,18 };
        int ans = 4;
        assert(ans == s.lengthOfLIS(input));
    }
    {
        vector<int> input{ 0,1,0,3,2,3 };
        int ans = 4;
        assert(ans == s.lengthOfLIS(input));
    }
    {
        vector<int> input{ 7,7,7,7,7,7,7 };
        int ans = 1;
        assert(ans == s.lengthOfLIS(input));
    }
    return 0;
}