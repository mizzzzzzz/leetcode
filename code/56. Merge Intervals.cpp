#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for (const vector<int>& i : intervals) {
            if (output.empty() || i[0] > output.back()[1]) {
                output.emplace_back(i);
            } else {
                output.back()[1] = std::max(output.back()[0], i[1]);
            }
        }
        return output;
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> input{ {1,3},{2,6},{8,10},{15,18} };
        vector<vector<int>> ans{ {1, 6}, {8, 10}, {15, 18} };
        assert(ans == s.merge(input));
    }
    {
        vector<vector<int>> input{{1, 4}, {4, 5}};
        vector<vector<int>> ans{{1, 5}};
        assert(ans == s.merge(input));
    }
    return 0;
}