#include <cassert>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }
        int k = 1;
        int i = 2;
        while (i < nums.size()) {
            if (nums[i] == nums[k] && nums[k - 1] == nums[k]) {
                ++i;
            } else {
                ++k;
                nums[k] = nums[i];
                ++i;    
            }           
        }
        return k + 1;
    }
    
private:
    int firstSol(vector<int>& nums) {
        int k = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[k]) {
                if (k == 0) {
                    ++i;
                    ++k;
                } else if (nums[k - 1] == nums[k]) {
                    ++i;
                } else {
                    ++k;
                    nums[k] = nums[i];
                    ++i;    
                }
            } else {
                ++k;
                nums[k] = nums[i];
                ++i;
            }
        }
        return k + 1;
    }
};