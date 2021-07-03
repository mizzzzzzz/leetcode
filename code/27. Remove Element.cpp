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

// https://leetcode.com/problems/remove-element/
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int k = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                ++k;
            }
            ++i;
        }
        return k;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 3, 2, 2, 3};
        int val = 3;;
        int k = 2;
        vector<int> output{ 2, 2, 2, 3};
        assert(k == s.removeElement(input, val));
    }
    return 0;
}