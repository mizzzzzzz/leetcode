[1mdiff --git a/code/57. Insert Interval.cpp b/code/57. Insert Interval.cpp[m
[1mindex a1d1782..335c406 100644[m
[1m--- a/code/57. Insert Interval.cpp[m	
[1m+++ b/code/57. Insert Interval.cpp[m	
[36m@@ -1,73 +1,79 @@[m
 #include <algorithm>[m
 #include <cassert>[m
[32m+[m[32m#include <queue>>[m
[32m+[m[32m#include <utility>[m
 #include <vector>[m
 [m
[32m+[m[32musing std::pair;[m
[32m+[m[32musing std::queue;[m
 using std::vector;[m
[32m+[m
 class Solution {[m
 public:[m
[31m-    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)[m
[31m-    {[m
[31m-        if (intervals.empty()) {[m
[31m-            return { newInterval };[m
[31m-        }[m
[31m-        vector<vector<int>> output;[m
[31m-        int n = intervals.size();[m
[31m-        int i = 0;[m
[31m-        while (i < n && intervals[i][1] < newInterval[0]) {[m
[31m-            output.emplace_back(intervals[i]);[m
[31m-            ++i;[m
[31m-        }[m
[31m-[m
[31m-        int newMin = i < n ? std::min(intervals[i][0], newInterval[0]) : newInterval[0];[m
[31m-        while (i < n && intervals[i][0] <= newInterval[1]) {[m
[31m-            ++i;[m
[31m-        }[m
[31m-        int newMax = i > 0 ? std::max(intervals[i - 1][1], newInterval[1]) : newInterval[1];[m
[31m-        output.emplace_back(vector<int>{ newMin, newMax });[m
[31m-[m
[31m-        if (i < n) {[m
[31m-            output.insert(output.end(), intervals.begin() + i, intervals.end());[m
[32m+[m[32m    int uniquePaths(int m, int n)[m
[32m+[m[32m    {[m[41m        [m
[32m+[m[32m        vector<vector<int>> v;[m
[32m+[m[32m        for (int i = 0; i < m; i++) {[m
[32m+[m[32m            v.emplace_back(vector<int>(n));[m
[32m+[m[32m            for (int j = 0; j < n; j++) {[m
[32m+[m[32m                if (i == 0 || j == 0) {[m
[32m+[m[32m                    v[i][j] = 1;[m
[32m+[m[32m                } else {[m
[32m+[m[32m                    v[i][j] = v[i - 1][j] + v[i][j - 1];[m
[32m+[m[32m                }[m
[32m+[m[32m            }[m
         }[m
[31m-        return output;[m
[32m+[m[32m        return v[m - 1][n - 1];[m
     }[m
 [m
 private:[m
[31m-    bool isOverlapped(const vector<int>& a, const vector<int>& b)[m
[31m-    {[m
[31m-        return a[1] >= b[0];[m
[31m-    }[m
[32m+[m[32m    using pii = pair<int, int>;[m
[32m+[m[32m    struct entry {[m
[32m+[m[32m        int count;[m
[32m+[m[32m        int numPath;[m
[32m+[m[32m    };[m
 [m
[31m-    vector<vector<int>> checkAndInsert(vector<vector<int>>& intervals, vector<int>& newInterval)[m
[32m+[m[32m    int bottomUp(int m, int n)[m
     {[m
[31m-        if (intervals.empty()) {[m
[31m-            return{ newInterval };[m
[31m-        }[m
[31m-        auto func = [&](vector<vector<int>>& o, const vector<int>& ni) {[m
[31m-            if (!o.empty() && isOverlapped(o.back(), ni)) {[m
[31m-                o.back()[1] = std::max(o.back()[1], ni[1]);[m
[31m-            } else {[m
[31m-                o.emplace_back(ni);[m
[31m-            }[m
[31m-        };[m
[31m-        vector<vector<int>> output;[m
[31m-        int i = 0;[m
[31m-        while (i < intervals.size()) {[m
[31m-            if (newInterval[0] < intervals[i][0]) {[m
[31m-                func(output, newInterval);[m
[31m-                while (i < intervals.size()) {[m
[31m-                    func(output, intervals[i]);[m
[31m-                    ++i;[m
[32m+[m[32m        vector<vector<entry>> v;[m
[32m+[m[32m        for (int i = 0; i < m; i++) {[m
[32m+[m[32m            v.emplace_back(vector<entry>(n));[m
[32m+[m[32m            for (int j = 0; j < n; j++) {[m
[32m+[m[32m                v[i][j].count = 0;[m
[32m+[m[32m                if (i + 1 < m) {[m
[32m+[m[32m                    ++v[i][j].count;[m
[32m+[m[32m                }[m
[32m+[m[32m                if (j + 1 < n) {[m
[32m+[m[32m                    ++v[i][j].count;[m
                 }[m
[31m-                break;[m
[31m-            } else {[m
[31m-                output.emplace_back(intervals[i]);[m
[31m-                ++i;[m
             }[m
         }[m
[31m-        if (output.size() == intervals.size()) {[m
[31m-            func(output, newInterval);[m
[32m+[m[32m        v[m - 1][n - 1].count = 1;[m
[32m+[m[32m        v[m - 1][n - 1].numPath = 1;[m
[32m+[m
[32m+[m[32m        queue<pii> q;[m
[32m+[m[32m        q.emplace(m - 1, n - 1);[m
[32m+[m[32m        while (!q.empty()) {[m
[32m+[m[32m            const pii& index = q.front();[m
[32m+[m[32m            entry& e = v[index.first][index.second];[m
[32m+[m[32m            --e.count;[m
[32m+[m[32m            if (e.count == 0) {[m
[32m+[m[32m                if (index.first - 1 >= 0) {[m
[32m+[m[32m                    q.emplace(index.first - 1, index.second);[m
[32m+[m[32m                }[m
[32m+[m[32m                if (index.second - 1 >= 0) {[m
[32m+[m[32m                    q.emplace(index.first, index.second - 1);[m
[32m+[m[32m                }[m
[32m+[m[32m                if (index.first + 1 < m) {[m
[32m+[m[32m                    e.numPath += v[index.first + 1][index.second].numPath;[m
[32m+[m[32m                }[m
[32m+[m[32m                if (index.second + 1 < n) {[m
[32m+[m[32m                    e.numPath += v[index.first][index.second + 1].numPath;[m
[32m+[m[32m                }[m
[32m+[m[32m            }[m
[32m+[m[32m            q.pop();[m
         }[m
[31m-        return output;[m
[32m+[m[32m        return v[0][0].numPath;[m
     }[m
 };[m
 [m
[36m@@ -75,52 +81,20 @@[m [mint main()[m
 {[m
     Solution s;[m
     {[m
[31m-        vector<vector<int>> input{ { 1, 5 } };[m
[31m-        vector<int> newInterval{ 0, 0 };[m
[31m-        vector<vector<int>> ans{ { 0, 0 }, {1, 5} };[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[32m+[m[32m        assert(3 == s.uniquePaths(3, 2));[m
     }[m
     {[m
[31m-        vector<vector<int>> input{ { 1, 5 } };[m
[31m-        vector<int> newInterval{ 0, 3 };[m
[31m-        vector<vector<int>> ans{ { 0, 5 } };[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[32m+[m[32m        assert(28 == s.uniquePaths(3, 7));[m
     }[m
     {[m
[31m-        vector<vector<int>> input{ { 1, 3 },{ 6, 9 } };[m
[31m-        vector<int> newInterval{ 4, 5 };[m
[31m-        vector<vector<int>> ans{ { 1, 3 }, {4, 5},  { 6, 9 } };[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[32m+[m[32m        assert(28 == s.uniquePaths(7, 3));[m
     }[m
     {[m
[31m-        vector<vector<int>> input{{1, 3}, {6, 9}};[m
[31m-        vector<int> newInterval{ 2, 5 };[m
[31m-        vector<vector<int>> ans{{1, 5}, {6, 9}};[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[32m+[m[32m        assert(6 == s.uniquePaths(3, 3));[m
     }[m
     {[m
[31m-        vector<vector<int>> input{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};[m
[31m-        vector<int> newInterval{ 4, 8 };[m
[31m-        vector<vector<int>> ans{{1, 2}, {3, 10}, {12, 16}};[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[31m-    }[m
[31m-    {[m
[31m-        vector<vector<int>> input{};[m
[31m-        vector<int> newInterval{ 5, 7 };[m
[31m-        vector<vector<int>> ans{{5, 7}};[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[31m-    }[m
[31m-    {[m
[31m-        vector<vector<int>> input{{1, 5}};[m
[31m-        vector<int> newInterval{ 2, 3 };[m
[31m-        vector<vector<int>> ans{{1, 5}};[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[31m-    }[m
[31m-    {[m
[31m-        vector<vector<int>> input{{1, 5}};[m
[31m-        vector<int> newInterval{ 2, 7 };[m
[31m-        vector<vector<int>> ans{{1, 7}};[m
[31m-        assert(ans == s.insert(input, newInterval));[m
[32m+[m[32m        assert(193536720 == s.uniquePaths(23, 12));[m
     }[m
[32m+[m
     return 0;[m
 }[m
\ No newline at end of file[m
[1mdiff --git a/code/57. Insert Interval.txt b/code/57. Insert Interval.txt[m
[1mindex 97c8b25..d58e220 100644[m
[1m--- a/code/57. Insert Interval.txt[m	
[1m+++ b/code/57. Insert Interval.txt[m	
[36m@@ -1,2 +1,2 @@[m
[31m-Runtime: 4 ms, faster than 99.88% of C++ online submissions for Insert Interval.[m
[31m-Memory Usage: 17.1 MB, less than 70.13% of C++ online submissions for Insert Interval.[m
\ No newline at end of file[m
[32m+[m[32mRuntime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.[m
[32m+[m[32mMemory Usage: 6.4 MB, less than 38.62% of C++ online submissions for Unique Paths.[m
\ No newline at end of file[m
