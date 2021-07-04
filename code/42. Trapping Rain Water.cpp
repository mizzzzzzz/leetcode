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

// https://leetcode.com/problems/candy/
class Solution
{
public:
    int trap(vector<int>& height)
    {
        return largestRectang(height);
    }

private:
    int largestRectang(vector<int>& height)
    {
        stack<int> s;
        int ans = 0;
        int i = 0;
        while (i < height.size()) {
            if (s.empty() || height[s.top()] > height[i]) {
                s.emplace(i);
                ++i;
            } else {
                int pre = s.top();
                s.pop();

                if (!s.empty()) {
                    int h = std::min(height[s.top()], height[i]);
                    ans += (h - height[pre]) * (i - s.top() - 1);
                }
            }
        }
        return ans;
    }


    int betterSol(vector<int>& height)
    {
        int l = 0, r = height.size() - 1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = std::max(level, lower);
            water += level - lower;
        }
        return water;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 0,1,0,2,1,0,1,3,2,1,2,1 };
        int ans = 6;
        assert(ans == s.trap(input));
    }
    {
        vector<int> input{ 4,2,0,3,2,5 };
        int ans = 9;
        assert(ans == s.trap(input));
    }
    return 0;
}