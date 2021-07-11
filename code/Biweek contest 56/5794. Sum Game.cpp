#include <algorithm>
#include <cassert>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <queue>
#include <string>

using std::string;
using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::pair;
using std::priority_queue;
static int R = 0;
static int C = 0;

class Solution
{
public:
    bool sumGame(string num)
    {
        int diff = 0;
        int q = 0;;

        int n = num.size();
        int half = n / 2;
        for (int i = 0; i < n; ++i) {
            
            if (i < half) {
                if (num[i] == '?') {
                    ++q;
                } else {
                    diff += num[i] - '0';
                }
            } else {
                if (num[i] == '?') {
                    --q;
                } else {
                    diff -= num[i] - '0';
                }
            }
        }

        if (diff * 2 == q * -9) {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    {
        string input("9?");
        bool output = true;
        assert(output == s.sumGame(input));
    }
    {
        string input("25??");
        bool output = true;
        assert(output == s.sumGame(input));
    }
    {
        string input("?3295???");
        bool output = false;
        assert(output == s.sumGame(input));
    }
    {
        string input("5023");
        bool output = false;
        assert(output== s.sumGame(input));

    }
    
    return 0;
}