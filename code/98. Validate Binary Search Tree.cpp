#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <utility>

using std::make_pair;
using std::string;
using std::queue;
using std::unordered_map;
using std::pair;
using std::vector;

// https://leetcode.com/problems/validate-binary-search-tree/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     static TreeNode* generate(vector<int> input)
     {
         vector<TreeNode*> nodes;
         for (int i = 0; i < input.size(); ++i) {
             nodes.emplace_back((input[i] == -1) ? nullptr : new TreeNode(input[i]));
         }
         for (int i = 0; i < input.size(); ++i) {
             if (!nodes[i]) {
                 continue;
             }
             int leftId = 2 * i + 1;
             if (leftId < input.size() && nodes[leftId]) {
                 nodes[i]->left = nodes[leftId];
             }
             int rightId = 2 * i + 2;
             if (rightId < input.size() && nodes[rightId]) {
                 nodes[i]->right = nodes[rightId];
             }
         }
         return nodes[0];
     }
};

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return isValidBST(root, INT_MAX, INT_MIN);
    }

    bool isValidBST(TreeNode* root, int maxVal, int minVal)
    {
        if (!root) {
            return true;
        }
        if (root->val == INT_MIN && root->left) {
            return false;
        }
        if (root->val == INT_MAX && root->right) {
            return false;
        }
        if (root->val < minVal || root->val > maxVal) {
            return false;
        }
        int newMaxVal = (root->val > INT_MIN) ? root->val - 1 : INT_MIN;
        int newMinVal = (root->val < INT_MAX) ? root->val + 1 : INT_MAX;
        return isValidBST(root->left, newMaxVal, minVal) && isValidBST(root->right, maxVal, newMinVal);
    }
};

int main()
{
    Solution s;
    {
        TreeNode* input(TreeNode::generate(vector<int>{5, 4, 6, -1, -1, 3, 7}));
        bool ans = false;;
        assert(ans == s.isValidBST(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{3, 1, 5, 0, 2, 4, 6}));
        bool ans = true;;
        assert(ans == s.isValidBST(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{5, 4, 6, -1, -1, 3, 7}));
        bool ans = false;;
        assert(ans == s.isValidBST(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{2, 1, 3}));
        bool ans = true;
        assert(ans == s.isValidBST(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{5, 1, 4, -1, -1, 3, 6}));
        bool ans = false;
        assert(ans == s.isValidBST(input));
    }
    return 0;
}