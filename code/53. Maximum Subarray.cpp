#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        return linearSolution(nums);
    }
private:
    int linearSolution(vector<int>& nums)
    {
        int maxSum = nums[0];
        int tmpSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            tmpSum = std::max(nums[i], nums[i] + tmpSum);
            maxSum = std::max(tmpSum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ -2,1,-3,4,-1,2,1,-5,4 };
        int ans = 6;
        assert(ans == s.maxSubArray(input));
    }
    {
        vector<int> input{ 1 };
        int ans = 1;
        assert(ans == s.maxSubArray(input));
    }
    {
        vector<int> input{ -1 };
        int ans = -1;
        assert(ans == s.maxSubArray(input));
    }
    {
        vector<int> input{ -2, 1 };
        int ans = 1;
        assert(ans == s.maxSubArray(input));
    }
    {
        vector<int> input{ 5,4,-1,7,8 };
        int ans = 23;
        assert(ans == s.maxSubArray(input));
    }
    return 0;
}