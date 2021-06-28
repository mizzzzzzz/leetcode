#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>

using std::make_pair;
using std::string;
using std::queue;
using std::unordered_map;
using std::pair;
using std::stack;
using std::vector;

// https://leetcode.com/problems/product-of-array-except-self/
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> ans(nums.size(), 1);
        int product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            product *= nums[i];
            ans[i] = product;
        }
        product = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            ans[i] = ans[i - 1] * product;
            product *= nums[i];
        }
        ans[0] = product;
        return ans;
    }

    vector<int> firstSol(vector<int>& nums)
    {
        int p = 1;
        vector<int> ans(nums.size(), 0);
        firstSolRec(nums, 0, ans, p);
        return ans;
    }

    int firstSolRec(vector<int>& nums, int i, vector<int>& ans, int prev)
    {
        if (i >= nums.size()) {
            return 1;
        }
        int next = firstSolRec(nums, i + 1, ans, prev * nums[i]);
        ans[i] = prev * next;
        return next * nums[i];
    }
};