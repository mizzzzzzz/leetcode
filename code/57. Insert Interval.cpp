#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

// https://leetcode.com/problems/insert-interval/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (intervals.empty()) {
            return { newInterval };
        }
        vector<vector<int>> output;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            output.emplace_back(intervals[i]);
            ++i;
        }

        int newMin = i < n ? std::min(intervals[i][0], newInterval[0]) : newInterval[0];
        while (i < n && intervals[i][0] <= newInterval[1]) {
            ++i;
        }
        int newMax = i > 0 ? std::max(intervals[i - 1][1], newInterval[1]) : newInterval[1];
        output.emplace_back(vector<int>{ newMin, newMax });

        if (i < n) {
            output.insert(output.end(), intervals.begin() + i, intervals.end());
        }
        return output;
    }

private:
    bool isOverlapped(const vector<int>& a, const vector<int>& b)
    {
        return a[1] >= b[0];
    }

    vector<vector<int>> checkAndInsert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (intervals.empty()) {
            return{ newInterval };
        }
        auto func = [&](vector<vector<int>>& o, const vector<int>& ni) {
            if (!o.empty() && isOverlapped(o.back(), ni)) {
                o.back()[1] = std::max(o.back()[1], ni[1]);
            } else {
                o.emplace_back(ni);
            }
        };
        vector<vector<int>> output;
        int i = 0;
        while (i < intervals.size()) {
            if (newInterval[0] < intervals[i][0]) {
                func(output, newInterval);
                while (i < intervals.size()) {
                    func(output, intervals[i]);
                    ++i;
                }
                break;
            } else {
                output.emplace_back(intervals[i]);
                ++i;
            }
        }
        if (output.size() == intervals.size()) {
            func(output, newInterval);
        }
        return output;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> input{ { 1, 5 } };
        vector<int> newInterval{ 0, 0 };
        vector<vector<int>> ans{ { 0, 0 }, {1, 5} };
        assert(ans == s.insert(input, newInterval));
    }
    {
        vector<vector<int>> input{ { 1, 5 } };
        vector<int> newInterval{ 0, 3 };
        vector<vector<int>> ans{ { 0, 5 } };
        assert(ans == s.insert(input, newInterval));
    }
    {
        vector<vector<int>> input{ { 1, 3 },{ 6, 9 } };
        vector<int> newInterval{ 4, 5 };
        vector<vector<int>> ans{ { 1, 3 }, {4, 5},  { 6, 9 } };
        assert(ans == s.insert(input, newInterval));
    }
    {
        vector<vector<int>> input{{1, 3}, {6, 9}};
        vector<int> newInterval{ 2, 5 };
        vector<vector<int>> ans{{1, 5}, {6, 9}};
        assert(ans == s.insert(input, newInterval));
    }
    {
        vector<vector<int>> input{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
        vector<int> newInterval{ 4, 8 };
        vector<vector<int>> ans{{1, 2}, {3, 10}, {12, 16}};
        assert(ans == s.insert(input, newInterval));
    }
    {
        vector<vector<int>> input{};
        vector<int> newInterval{ 5, 7 };
        vector<vector<int>> ans{{5, 7}};
        assert(ans == s.insert(input, newInterval));
    }
    {
        vector<vector<int>> input{{1, 5}};
        vector<int> newInterval{ 2, 3 };
        vector<vector<int>> ans{{1, 5}};
        assert(ans == s.insert(input, newInterval));
    }
    {
        vector<vector<int>> input{{1, 5}};
        vector<int> newInterval{ 2, 7 };
        vector<vector<int>> ans{{1, 7}};
        assert(ans == s.insert(input, newInterval));
    }
    return 0;
}