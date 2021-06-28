#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] < target) {
                    ++j;
                } else if (nums[j] + nums[k] > target) {
                    --k;
                } else {
                    ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    while ((j < nums.size() - 1) && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    while ((k > i) && nums[k] == nums[k - 1]) {
                        --k;
                    }
                    ++j;
                    --k;
                }
            }
           
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ -1, 0, 1, 2, -1, -4 };
        vector<vector<int>> ans = { { -1, -1, 2 }, { -1, 0, 1 } };
        assert(ans == s.threeSum(input));
    }
    {
        vector<int> input{ 0, 0, 0, 0 };
        vector<vector<int>> ans = { {0 ,0 ,0} };
        assert(ans == s.threeSum(input));
    }
    {
        vector<int> input{};
        vector<vector<int>> ans = {};
        assert(ans == s.threeSum(input));
    }
    {
        vector<int> input{ 0 };
        vector<vector<int>> ans = {};
        assert(ans == s.threeSum(input));
    }
    return 0;
}