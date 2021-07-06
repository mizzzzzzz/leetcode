#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

// https://leetcode.com/problems/missing-ranges/
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        for (int n : nums) {
            if (n > lower) {
                string s = std::to_string(nums[start]);
                if (n - 1 > lower) {
                    s += "->" + std::to_string(n);
                }
                ans.emplace_back(s);
            }
            if (n == upper) {
                return ans;
            }
            lower = n + 1;
        }
        if (lower <= upper) {
            string s = std::to_string(lower);
            if (upper - 1 > lower) {
                s += "->" + std::to_string(upper);
            }
            ans.emplace_back(s);
        }
        return ans;
    }
};