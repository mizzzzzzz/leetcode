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
    void moveZeroes(vector<int>& nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 1, 0, 1 };
        vector<int> output{ 1, 1, 0 };
        s.moveZeroes(input);
        assert(output == input);
    }
    {
        vector<int> input{ 0, 1, 0, 3, 12};
        vector<int> output{ 1, 3, 12, 0 ,0 };
        s.moveZeroes(input);
        assert(output == input);
    }
    return 0;
}