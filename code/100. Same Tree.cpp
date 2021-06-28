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

// https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return !p && !q;
    }
};

int main()
{
    Solution s;
    {
        TreeNode* p(TreeNode::generate(vector<int>{1, 2, 3}));
        TreeNode* q(TreeNode::generate(vector<int>{1, 2, 3}));
        bool ans = true;
        assert(ans == s.isSameTree(p, q));
    }
    {
        TreeNode* p(TreeNode::generate(vector<int>{1, 2}));
        TreeNode* q(TreeNode::generate(vector<int>{1, -1, 2}));
        bool ans = false;
        assert(ans == s.isSameTree(p, q));
    }
    {
        TreeNode* p(TreeNode::generate(vector<int>{1, 2, 1}));
        TreeNode* q(TreeNode::generate(vector<int>{1, 1, 2}));
        bool ans = false;
        assert(ans == s.isSameTree(p, q));
    }
    return 0;
}