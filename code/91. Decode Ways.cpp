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

class Solution {
public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        if (!isValidSD(s, 0)) {
            return 0;
        }
        dp[0] = dp[1] = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            // single digit
            if (isValidSD(s, i)) {
                dp[i + 1] += dp[i];
            }
            ////double digit
            if (isValidDD(s, i - 1, i)) {
                dp[i + 1] += dp[i - 1];
            }
            if (dp[i + 1] == 0) {
                return 0;
            }
        }
        return dp[s.size()];
    }
private:
    bool isValidSD(const string& s, int i)
    {
        return (s[i] >= '1' && s[i] <= '9');
    }

    bool isValidDD(const string& s, int i, int j)
    {
        if (s[i] > '2' || s[i] <= '0') {
            return false;
        }
        if (s[i] == '2' && s[j] > '6') {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    {
        string input{"12"};
        int ans = 2;
        assert(ans == s.numDecodings(input));
    }
    {
        string input{"226"};
        int ans = 3;
        assert(ans == s.numDecodings(input));
    }
    {
        string input{"0"};
        int ans = 0;
        assert(ans == s.numDecodings(input));
    }
    {
        string input{"06"};
        int ans = 0;
        assert(ans == s.numDecodings(input));
    }
    return 0;
}