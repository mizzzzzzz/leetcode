#include <cassert>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() {
            return 0;
        }
        int k = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[k] != nums[i]) {
                nums[++k] = nums[i];
            }
            ++i;
        }
        return k + 1;
    }
};