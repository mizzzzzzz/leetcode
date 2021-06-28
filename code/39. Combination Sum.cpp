#include <algorithm>
#include <cassert>
#include <vector>
using std::vector;

// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        ans.clear();
        std::sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        func(candidates, target, 0, tmp);
        return ans;
    }

private:
    vector<vector<int>> ans;

    void func(vector<int>& candidates, int target, int index, vector<int>& tmp)
    {
        for (size_t i = index; i < candidates.size(); ++i) {
            if (target - candidates[i] == 0) {
                tmp.emplace_back(candidates[i]);
                ans.emplace_back(tmp);
                tmp.pop_back();
                break;
            } else if (target - candidates[i] > 0) {
                tmp.emplace_back(candidates[i]);
                func(candidates, target - candidates[i], i, tmp);
                tmp.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 2 };
        int target = 1;
        vector<vector<int>> output = s.combinationSum(input, target);
        vector<vector<int>> ans{};
        assert(ans == output);
    }
    {
        vector<int> input{ 1 };
        int target = 1;
        vector<vector<int>> output = s.combinationSum(input, target);
        vector<vector<int>> ans{ { 1 } };
        assert(ans == output);
    }
    {
        vector<int> input{ 1 };
        int target = 2;
        vector<vector<int>> output = s.combinationSum(input, target);
        vector<vector<int>> ans{ { 1, 1 } };
        assert(ans == output);
    }
    {
        vector<int> input{ 2,3,6,7 };
        int target = 7;
        vector<vector<int>> output = s.combinationSum(input, target);
        vector<vector<int>> ans{ { 2, 2, 3 },{ 7 } };
        assert(ans == output);
    }
    return 0;
}