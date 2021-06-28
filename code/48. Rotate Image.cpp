#include <algorithm>
#include <cassert>
#include <vector>
using std::vector;

// https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        flipRowCol(matrix);
        flipCol(matrix);
    }
private:
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void flipRowCol(vector<vector<int>>& matrix)
    {
        size_t n = matrix.size();
        for (size_t row = 0; row < n; ++row) {
            for (size_t col = row + 1; col < n; ++col) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }

    void flipCol(vector<vector<int>>& matrix)
    {
        size_t n = matrix.size();
        for (size_t row = 0; row < n; ++row) {
            for (size_t col = 0; col < n / 2; ++col) {
                swap(matrix[row][col], matrix[row][n - col - 1]);
            }
        }
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> input{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        s.rotate(input);
        vector<vector<int>> ans{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
        assert(ans == input);
    }
    {
        vector<vector<int>> input{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        s.rotate(input);
        vector<vector<int>> ans{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
        assert(ans == input);
    }
    {
        vector<vector<int>> input{ {1} };
        s.rotate(input);
        vector<vector<int>> ans{ {1} };
        assert(ans == input);
    }
    {
        vector<vector<int>> input{{1, 2}, {3, 4}};
        s.rotate(input);
        vector<vector<int>> ans{{3, 1}, {4, 2}};
        assert(ans == input);
    }
    return 0;
}