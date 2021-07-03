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
    int candy(vector<int>& ratings)
    {
        int ans = 0;
        candy(ratings, 0, 0, ans);
        return ans;
    }

private:
    int candy(vector<int>& ratings, int i, int lastCandy, int& ans)
    {
        if (i >= ratings.size()) {
            return 0;
        }
        int curCandy = 1;
        if (i > 0 && (ratings[i] > ratings[i - 1])) {
            curCandy = lastCandy + 1;
        }

        int nextCandy = candy(ratings, i + 1, curCandy, ans);
        if (nextCandy >= curCandy && (i < ratings.size() - 1 && ratings[i] > ratings[i + 1])) {
            curCandy = nextCandy + 1;
        }
        ans += curCandy;
        return curCandy;
    }

    int betterCandy(vector<int>& ratings)
    {
        if (ratings.empty()) {
            return 0;
        }
        int ret = 1;
        int up = 0, down = 0, peak = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                peak = ++up;
                down = 0;
                ret += 1 + up;
            } else if (ratings[i - 1] == ratings[i]) {
                peak = up = down = 0;
                ret += 1;
            } else {
                up = 0;
                down++;
                ret += 1 + down + (peak >= down ? -1 : 0);
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 1, 0, 2 };
        int ans = 5;
        assert(ans == s.candy(input));
    }
    {
        vector<int> input{ 1, 2, 2 };
        int ans = 4;
        assert(ans == s.candy(input));
    }
    return 0;
}