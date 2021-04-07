#include <cassert>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> res2Num;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = res2Num.find(nums[i]);
            if (it != res2Num.end()) {
                return{ it->second, i };
            }
            int res = target - nums[i];
            res2Num.emplace(res, i);
        }
        assert(false);
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 2, 7, 11, 15 };
        int target = 9;
        vector<int> answer{ 0, 1 };
        auto output = s.twoSum(input, target);
        assert(answer == output);
    }
    {
        vector<int> input{ 3, 2, 4 };
        int target = 6;
        vector<int> answer{ 1, 2 };
        auto output = s.twoSum(input, target);
        assert(answer == output);
    }
    {
        vector<int> input{ 3, 3};
        int target = 6;
        vector<int> answer{ 0, 1 };
        auto output = s.twoSum(input, target);
        assert(answer == output);
    }
    return 0;
}