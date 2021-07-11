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

// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum % k) {
            return false;
        }
        int target = sum / k;

        vector<int> subset(k, 0);
        vector<bool> visited(nums.size(), false);
        return recur(nums, 0, 0, target, subset, visited);
    }

    bool recur(vector<int>& nums, int nid, int sid, int target, vector<int>& subset, vector<bool>& visited)
    {
        if (subset[sid] == target) {
            if (sid == subset.size() - 2) {
                return true;
            }
            return recur(nums, 0, sid + 1, target, subset, visited);
        }
        for (int i = nid; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }
            if (subset[sid] + nums[i] <= target) {
                subset[sid] += nums[i];
                visited[i] = true;

                int ret = recur(nums, nid + 1, sid, target, subset, visited);

                subset[sid] -= nums[i];
                visited[i] = false;
                if (ret) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums{ 1,1,1,1,2,2,2,2 };
        int k = 2;
        assert(true == s.canPartitionKSubsets(nums, k));
    }
}