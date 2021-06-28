#include <algorithm>
#include <array>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::array;
using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> output;
        unordered_map<string, size_t> m;
        for (const string& s : strs) {
            string sorted(s);
            sort(sorted.begin(), sorted.end());
            auto it = m.find(sorted);
            if (it == m.end()) {
                m.emplace(sorted, output.size());
                output.emplace_back(vector<string>{ s });
            } else {
                output[it->second].emplace_back(s);
            }
        }
        return output;
    }
};

int main()
{
    Solution s;
    {
        vector<string> input{ "" };
        vector<vector<string>> ans{ { "" } };
        vector<vector<string>> output = s.groupAnagrams(input);
        assert(ans == output);
    }
    {
        vector<string> input{ "a" };
        vector<vector<string>> ans{ { "a" } };
        vector<vector<string>> output = s.groupAnagrams(input);
        assert(ans == output);
    }
    {
        vector<string> input{ "eat","tea","tan","ate","nat","bat" };
        vector<vector<string>> ans{ { "eat", "tea", "ate" }, { "tan", "nat" }, { "bat" } };
        vector<vector<string>> output = s.groupAnagrams(input);
        assert(ans == output);
    }
    return 0;
}