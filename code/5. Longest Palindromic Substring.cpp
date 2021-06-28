#include <cassert>
#include <string>

using std::string;

// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2) {
            return s.substr(0, 1);
        }
        int maxC = 0;
        int maxW = 0;
        string paddedString = addPadding(s);
        for (int i = 0; i < paddedString.size(); ++i) {
            int width = 1;
            while ((i - width >= 0) && (i + width < paddedString.size()) && (paddedString[i - width] == paddedString[i + width])) {
                ++width;
            }
            --width;
            if (width > maxW) {
                maxW = width;
                maxC = i;
            }
        }
        return removePadding(paddedString.substr(maxC - maxW, 2 * maxW + 1));
    }

private:
    string addPadding(const string& s)
    {
        string paddedString;
        for (char c : s) {
            paddedString += '*';
            paddedString += c;
        }
        paddedString += '*';
        return paddedString;
    }

    string removePadding(const string& s)
    {
        string unpaddedString;
        for (char c : s) {
            if (c != '*') {
                unpaddedString += c;
            }
        }
        return unpaddedString;
    }
};

int main()
{
    Solution s;
    {
        string input = "babad";
        string ans = "bab";
        assert(ans == s.longestPalindrome(input));
    }
    {
        string input = "cbbd";
        string ans = "bb";
        assert(ans == s.longestPalindrome(input));
    }
    {
        string input = "a";
        string ans = "a";
        assert(ans == s.longestPalindrome(input));
    }
    {
        string input = "ac";
        string ans = "a";
        assert(ans == s.longestPalindrome(input));
    }
    {
        string input = "bb";
        string ans = "bb";
        assert(ans == s.longestPalindrome(input));
    }
    return 0;
}