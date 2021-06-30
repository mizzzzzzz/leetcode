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
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) ++res;
            }
        }
        return res;       
    }
    
private:
    int brute(string s) {
        if (s.empty()) return 0;
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            helper(s, i, i, res);
            helper(s, i, i + 1, res);
        }
        return res;
        
    }
    void helper(string s, int i, int j, int& res) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i; ++j; ++res;
        }
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