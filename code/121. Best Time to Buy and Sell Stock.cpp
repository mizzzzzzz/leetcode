#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using std::string;
using std::queue;
using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int ans = 0;
        int buyVal = prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] <= buyVal) {
                buyVal = prices[i];
                continue;
            }
            int profit = prices[i] - buyVal;
            if (profit > ans) {
                ans = profit;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 7,1,5,3,6,4 };
        int ans = 5;
        assert(ans == s.maxProfit(input));
    }
    {
        vector<int> input{ 7,6,4,3,1 };
        int ans = 0;
        assert(ans == s.maxProfit(input));
    }
    return 0;
}