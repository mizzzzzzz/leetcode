#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() < 2) {
            return s.size();
        }
        int ans = 1;
        unordered_set<char> chars;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (chars.count(s[i])) {
                chars.erase(s[j]);
                ++j;
            }
            chars.emplace(s[i]);
            int length = i - j + 1;
            if (length > ans) {
                ans = length;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        string input("abba");
        int ans = 2;
        assert(ans == s.lengthOfLongestSubstring(input));
    }
    {
        string input("abcabcbb");
        int ans = 3;
        assert(ans == s.lengthOfLongestSubstring(input));
    }
    {
        string input("bbbbb");
        int ans = 1;
        assert(ans == s.lengthOfLongestSubstring(input));
    }
    {
        string input("");
        int ans = 0;
        assert(ans == s.lengthOfLongestSubstring(input));
    }
    {
        string input(" ");
        int ans = 1;
        assert(ans == s.lengthOfLongestSubstring(input));
    }
    {
        string input("pwwkew");
        int ans = 3;
        assert(ans == s.lengthOfLongestSubstring(input));
    }
    return 0;
}