#include <cassert>
#include <stack>
#include <string>
#include <unordered_map>

using std::stack;
using std::string;
using std::unordered_map;

// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s)
    {
        static const unordered_map<char, char> close2Open {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        stack<char> st;
        for (auto& c : s) {
            auto it = close2Open.find(c);
            if (it == close2Open.end()) {
                st.emplace(c);
            } else {
                if (st.empty() || it->second != st.top()) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution s;
    {
        string input = "()";
        bool ans = true;
        assert(ans == s.isValid(input));
    }
    {
        string input = "()[]{}";
        bool ans = true;
        assert(ans == s.isValid(input));
    }
    {
        string input = "(]";
        bool ans = false;
        assert(ans == s.isValid(input));
    }
    {
        string input = "([)]";
        bool ans = false;
        assert(ans == s.isValid(input));
    }
    {
        string input = "{[]}";
        bool ans = true;
        assert(ans == s.isValid(input));
    }
    {
        string input = "[";
        bool ans = false;
        assert(ans == s.isValid(input));
    }
    {
        string input = "]";
        bool ans = false;
        assert(ans == s.isValid(input));
    }
    return 0;
}