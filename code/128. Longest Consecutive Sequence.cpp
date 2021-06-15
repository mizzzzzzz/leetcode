#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> s;
        for (int n : nums) {
            s.emplace(n);
        }
        int ans = 1;
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (s.find(n - 1) == s.end()) {
                int c = 1;
                int j = n + 1;
                while (s.find(j) != s.end()) {
                    ++j; ++c;
                    ans = std::max(ans, c);
                }
            }
        }
        return ans;
    }

private:
    int firstVersion(vector<int>& nums)
    {
        vector<vector<int>> ds;
        unordered_map<int, int> num2dsid;
        for (int n : nums) {
            if (num2dsid.count(n) > 0) {
                continue;
            }
            auto prev = num2dsid.find(n - 1);
            auto next = num2dsid.find(n + 1);
            if (prev == num2dsid.end() && next == num2dsid.end()) {
                // insert new element
                ds.emplace_back(vector<int>{n});
                num2dsid.emplace(n, ds.size() - 1);
            } else if (prev == num2dsid.end()) {
                // put it to related set
                ds[next->second].emplace_back(n);
                num2dsid.emplace(n, next->second);
            } else if (next == num2dsid.end()) {
                // put it to related set
                ds[prev->second].emplace_back(n);
                num2dsid.emplace(n, prev->second);
            } else {
                ds[prev->second].emplace_back(n);
                num2dsid.emplace(n, prev->second);
                if (prev->second != next->second) {
                    // merge next array to prev array
                    ds[prev->second].insert(ds[prev->second].end(), ds[next->second].begin(), ds[next->second].end());
                    // reindex next
                    for (int nn : ds[next->second]) {
                        num2dsid[nn] = prev->second;
                    }
                }
            }
        }
        size_t ans = 0;
        for (auto& entry : ds) {
            ans = std::max(ans, entry.size());
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ -4, -1, 4, -5, 1, -6, 9, -6, 0, 2, 2, 7, 0, 9, -3, 8, 9, -2, -6, 5, 0, 3, 4, -2 };
        int ans = 12;
        assert(ans == s.longestConsecutive(input));
    }
    {
        vector<int> input{ 1,2,0,1 };
        int ans = 3;
        assert(ans == s.longestConsecutive(input));
    }
    {
        vector<int> input{ 100,4,200,1,3,2 };
        int ans = 4;
        assert(ans == s.longestConsecutive(input));
    }
    {
        vector<int> input{ 0,3,7,2,5,8,4,6,0,1 };
        int ans = 9;
        assert(ans == s.longestConsecutive(input));
    }
    return 0;
}