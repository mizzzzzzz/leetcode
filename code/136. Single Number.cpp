#include <cassert>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret  = 0;
        for (int i : nums) {
            ret ^= i;            
        }
        return ret;
    }
};