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

// https://leetcode.com/problems/minimum-size-subarray-sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int i = 0;
        int j = 0;
        int sum = 0;
        while (i < nums.size()) {
            sum += nums[i];
            if (sum >= target) {
                while(j <= i && (sum - nums[j] >= target)) {
                    sum -= nums[j];
                    ++j;
                }               
                int l = i - j + 1;
                if (l < minLength) {
                    minLength = l;
                }
            }
            ++i;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};