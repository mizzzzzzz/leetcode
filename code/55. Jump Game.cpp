#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int i = 0;
        int maxReach = 0;
        while (i < nums.size() && i <= maxReach) {
            maxReach = std::max(i + nums[i], maxReach);
            ++i;
        }
        return i == nums.size();
    }
private:
    enum class Status {
        UNVISITED, NO, OKAY
    };

    bool canJumpRec(vector<int>& nums)
    {
        vector<Status> statuses(nums.size(), Status::UNVISITED);
        statuses.back() = Status::OKAY;

        if (canJumpUtil(nums, 0, statuses) == Status::OKAY) {
            return true;
        }
        return false;
    }

    Status canJumpUtil(const vector<int>& nums, size_t i, vector<Status>& status)
    {
        if (status[i] != Status::UNVISITED) {
            return status[i];
        }
        for (size_t s = 1; s <= nums[i]; ++s) {
            if (i + s < nums.size()) {
                if (canJumpUtil(nums, i + s, status) == Status::OKAY) {
                    return Status::OKAY;
                }
            }
        }
        return (status[i] = Status::NO);
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 2,3,1,1,4 };
        bool ans = true;
        assert(ans == s.canJump(input));
    }
    {
        vector<int> input{ 3,2,1,0,4 };
        bool ans = false;
        assert(ans == s.canJump(input));
    }
    return 0;
}