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

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
         return nodes.empty() ? nullptr : nodes[0];
     }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()
{
    Solution s;
    {
        TreeNode* input(TreeNode::generate(vector<int>{3, 9, 20, -1, -1, 15, 7}));
        int ans = 3;
        assert(ans == s.maxDepth(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{1, -1, 2}));
        int ans = 2;
        assert(ans == s.maxDepth(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{}));
        int ans = 0;
        assert(ans == s.maxDepth(input));
    }
    return 0;
}