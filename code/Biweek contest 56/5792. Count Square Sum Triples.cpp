#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
public:
    int countTriples(int n)
    {
        int ans = 0;
        unordered_set<int> s;
        for (int i = 1; i <= n; ++i) {
            s.emplace(i * i);
        }
        for (int i = 1; i <= n; ++i) {
            int si = i * i;
            for (int j = 1; j <= n; ++j) {
                int sj = j * j;
                if (s.count(si + sj) > 0) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        auto output = s.countTriples(2);
        assert(2 == output);
    }
    {
        auto output = s.countTriples(1);
        assert(0 == output);
    }
    {
        auto output = s.countTriples(5);
        assert(2 == output);
    }
    {
        auto output = s.countTriples(10);
        assert(4 == output);
    }
    return 0;
}