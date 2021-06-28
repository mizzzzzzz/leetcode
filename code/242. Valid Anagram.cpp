#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>

using std::make_pair;
using std::string;
using std::queue;
using std::unordered_map;
using std::pair;
using std::stack;
using std::vector;

// https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int smap[26] = {0};
        int tmap[26] = {0};
        for (char c : s) {
            ++smap[c - 'a'];
        }
        for (char c : t) {
            ++tmap[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (smap[i] != tmap[i]) {
                return false;
            }
        }
        return true;
    }
};