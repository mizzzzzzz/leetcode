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

// https://leetcode.com/problems/coin-change/
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (i >= c) {
                    dp[i] = std::min(dp[i], dp[i - c] + 1);
                }
            }
        }        
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }

private:
    int NtoNSolution(vector<int>& coins, int amount)
    {
        std::sort(coins.begin(), coins.end(), std::greater<>());
        int ans = greedy(coins, amount);
        bfs(coins, 0, amount, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void bfs(vector<int>& coins, int i, int target, int usedCoin, int& minUsedCoin)
    {
        if (i >= coins.size()) {
            return;
        }
        if (usedCoin >= minUsedCoin) {
            return;
        }
        int canUsedCoin = std::min((minUsedCoin - usedCoin), (target / coins[i]));
        for (int c = 0; c <= canUsedCoin; ++c) {
            if (target == 0) {
                if (minUsedCoin > usedCoin) {
                    minUsedCoin = usedCoin;
                }
            } else if (target > 0) {
                bfs(coins, i + 1, target, usedCoin, minUsedCoin);
            } else {
                break;
            }
            target -= coins[i];
            ++usedCoin;
        }
    }

    int greedy(vector<int>& coins, int target)
    {
        int ans = 0;
        for (int i = 0; i < coins.size(); ++i) {
            ans += (target / coins[i]);
            target %= coins[i];
        }
        if (target > 0) {
            return INT_MAX;
        }
        return target > 0 ? -1 : ans;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 1, 2, 5 };
        int amount = 11;
        int ans = 3;
        assert(ans == s.coinChange(input, amount));
    }
    {
        vector<int> input{ 2 };
        int amount = 3;
        int ans = -1;
        assert(ans == s.coinChange(input, amount));
    }
    {
        vector<int> input{ 1 };
        int amount = 0;
        int ans = 0;
        assert(ans == s.coinChange(input, amount));
    }
    {
        vector<int> input{ 1 };
        int amount = 1;
        int ans = 1;
        assert(ans == s.coinChange(input, amount));
    }
    {
        vector<int> input{ 1 };
        int amount = 2;
        int ans = 2;
        assert(ans == s.coinChange(input, amount));
    }
    {
        vector<int> input{ 25, 18, 5, 1 };
        int amount = 41;
        int ans = 3;
        assert(ans == s.coinChange(input, amount));
    }
    return 0;
}