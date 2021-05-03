#include <cassert>
#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

private:
    int linearSearch(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            if (target > nums[end] && target < nums[start]) {
                return -1;
            }
            if (target == nums[start]) {
                return start;
            }
            if (target == nums[end]) {
                return end;
            }
            if (target > nums[start]) {
                ++start;
            } else if (target < nums[end]) {
                --end;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 3,1 };
        int target = 1;
        int output = s.search(input, target);
        int ans = 1;
        assert(ans == output);
    }
    {
        vector<int> input{ 7, 8, 1, 2, 3, 4, 5, 6 };
        int target = 2;
        int output = s.search(input, target);
        int ans = 3;
        assert(ans == output);
    }
    {
        vector<int> input{ 3,1 };
        int target = 3;
        int output = s.search(input, target);
        int ans = 0;
        assert(ans == output);
    }
    {
        vector<int> input{ 3,5,1 };
        int target = 4;
        int output = s.search(input, target);
        int ans = -1;
        assert(ans == output);
    }
    {
        vector<int> input{ 4,5,6,7,0,1,2 };
        int target = 0;
        int output = s.search(input, target);
        int ans = 4;
        assert(ans == output);
    }
    {
        vector<int> input{ 4,5,6,7,0,1,2 };
        int target = 3;
        int output = s.search(input, target);
        int ans = -1;
        assert(ans == output);
    }
    {
        vector<int> input{ 1 };
        int target = 0;
        int output = s.search(input, target);
        int ans = -1;
        assert(ans == output);
    }
    {
        vector<int> input{ 1 };
        int target = 1;
        int output = s.search(input, target);
        int ans = 0;
        assert(ans == output);
    }
    return 0;
}