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

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int target = (1 + n) * n / 2;
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        return target - sum;
    }
};