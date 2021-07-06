#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

// https://leetcode.com/problems/summary-ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size();) {
            int start = i;
            int end = i + 1;
            while (end < n && nums[end] == nums[end - 1] + 1) {
                ++end;
            }
            string s = std::to_string(nums[start]);
            if (start < end - 1) {
                s += "->" + std::to_string(nums[end - 1]);
            }
            ans.emplace_back(s);
            i = end;
        }   
        return ans;
    }
};