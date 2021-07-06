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

// https://leetcode.com/problems/partition-labels
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int m[26];
        for (int i = 0; i < 26; ++i) {
            m[i] = INT_MIN;
        }

        for (int i = 0; i < s.size(); ++i) {
            m[s[i] - 'a'] = std::max(m[s[i] - 'a'], i);
        }
        
        vector<int> ans;
        int lasti = 0;
        int maxi = -1;
        for (int i = 0; i < s.size(); ++i) {
            maxi = std::max(maxi, m[s[i] - 'a']);
            if (i == maxi) {
                ans.emplace_back(i - lasti + 1);
                lasti = i + 1;
            }
        }
        return ans;
    }
};