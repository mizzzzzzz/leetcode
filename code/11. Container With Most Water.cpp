#include <algorithm>
#include <cassert>
#include <stack>
#include <vector>

using std::vector;
using std::stack;

// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxArea = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            if (height[i] > height[j]) {
                maxArea = std::max(maxArea, (j - i) * height[j]);
                --j;
            } else {
                maxArea = std::max(maxArea, (j - i) * height[i]);
                ++i;
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 1,8,6,2,5,4,8,3,7 };
        int ans = 49;
        assert(ans == s.maxArea(input));
    }
    {
        vector<int> input{ 1,1 };
        int ans = 1;
        assert(ans == s.maxArea(input));
    }
    {
        vector<int> input{ 4,3,2,1,4 };
        int ans = 16;
        assert(ans == s.maxArea(input));
    }
    {
        vector<int> input{ 1,2,1 };
        int ans = 2;
        assert(ans == s.maxArea(input));
    }
    return 0;
}