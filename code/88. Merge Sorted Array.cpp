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

// https://leetcode.com/problems/merge-sorted-array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insertId = m + n - 1;
        --m;
        --n;
        while (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                nums1[insertId] = nums1[m];
                --m;
            } else {
                nums1[insertId] = nums2[n];
                --n;
            }
            --insertId;   
        }
        
        while (m >= 0) {
            nums1[insertId] = nums1[m];
            --insertId;   
            --m;
        } 
        while (n >= 0) {
            nums1[insertId] = nums2[n];
            --insertId;   
            --n;
        }
    }
};