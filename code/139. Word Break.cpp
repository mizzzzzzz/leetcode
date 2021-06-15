#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::queue;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (const string& w : wordDict) {
                if (i >= w.size() && dp[i - w.size()] && s.substr(i - w.size(), w.size()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution s;
    {
        string input("aaaaaaa");
        vector<string> dict{ "aaaa", "aaa" };
        bool ans = true;
        assert(ans == s.wordBreak(input, dict));
    }
    {
        string input("leetcode");
        vector<string> dict{ "leet", "code" };
        bool ans = true;
        assert(ans == s.wordBreak(input, dict));
    }
    {
        string input("applepenapple");
        vector<string> dict{ "apple", "pen" };
        bool ans = true;
        assert(ans == s.wordBreak(input, dict));
    }
    {
        string input("catsandog");
        vector<string> dict{ "cats","dog","sand","and","cat"};
        bool ans = false;
        assert(ans == s.wordBreak(input, dict));
    }
    return 0;
}