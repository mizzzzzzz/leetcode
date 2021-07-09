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

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }
        int pre;
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; ++j) {
            cur[j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            pre = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; ++j) {
                int temp = cur[j];
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre;
                } else {
                    cur[j] = 1 + std::min(pre, std::min(cur[j - 1], cur[j]));
                }
                pre = temp;
            }
        }
        return cur[n];
    }
    
private:
    int twoVector(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) {
            return n;
        }
        if (n == 0) {
            return m;
        }
        vector<int> pre(n + 1, 0);
        vector<int> cur(n + 1, 0);
        
        for (int j = 1; j <= n; ++j) {
            pre[j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            cur[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre[j - 1];
                } else {
                    cur[j] = 1 + std::min(pre[j - 1], std::min(cur[j - 1], pre[j]));
                }
            }
            
            for (int j = 0; j <= n; ++j) {
                pre[j] = cur[j];
            }
        }
        return cur[n];
    }
};