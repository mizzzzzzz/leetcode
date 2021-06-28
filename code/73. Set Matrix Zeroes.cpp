#include <algorithm>
#include <cassert>
#include <vector>

using std::vector;

// https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        /*
            [
            [1,2,3,4],
            [5,0,7,8],
            [0,10,11,12],
            [13,14,15,0]
            ]
        */
        bool firstRow = false;
        bool firstCol = false;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    firstRow |= (i == 0);
                    firstCol |= (j == 0);
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = matrix[i].size() - 1; j >= 0; --j) {
                if (i == 0) {
                    if (firstRow) {
                        matrix[i][j] = 0;
                    }
                } else if (j == 0) {
                    if (firstCol) {
                        matrix[i][j] = 0;
                    }
                } else if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>> input{{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
        vector<vector<int>> ans{{0, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
        s.setZeroes(input);
        assert(ans == input);
    }
    {
        vector<vector<int>> input{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        vector<vector<int>> ans{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
        s.setZeroes(input);
        assert(ans == input);
    }
    {
        vector<vector<int>> input{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        vector<vector<int>> ans{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
        s.setZeroes(input);
        assert(ans == input);
    }
    {
        vector<vector<int>> input{ { 0 }, { 1 } };
        vector<vector<int>> ans{ { 0 }, { 0 }};
        s.setZeroes(input);
        assert(ans == input);
    }
    return 0;
}