#include <algorithm>
#include <cassert>
#include <vector>
#include <string>

using std::string;
using std::vector;

// https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (!isAlphanumeric(s[start])) {
                ++start;
                continue;
            }
            if(!isAlphanumeric(s[end])) {
                --end;
                continue;
            }
            if (toLowercase(s[start]) != toLowercase(s[end])) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }

    bool isAlphanumeric(char c)
    {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }

    char toLowercase(char c)
    {   
        if (c >= 'A' && c <= 'Z') {
            return c - ('Z' - 'z');
        }
        return c;
    }
};

int main()
{
    Solution s;
    {
        string input(".,");
        bool ans = true;
        assert(ans == s.isPalindrome(input));
    }
    {
        string input(" ");
        bool ans = true;
        assert(ans == s.isPalindrome(input));
    }
    {
        string input("A man, a plan, a canal: Panama");
        bool ans = true;
        assert(ans == s.isPalindrome(input));
    }
    {
        string input("race a car");
        bool ans = false;
        assert(ans == s.isPalindrome(input));
    }
    return 0;
}