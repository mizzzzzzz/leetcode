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

int null = 9999;
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
             nodes.emplace_back((input[i] == null) ? nullptr : new TreeNode(input[i]));
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

     static bool compare(TreeNode* p, TreeNode* q)
     {
         if (p && q && p->val == q->val) {
             return compare(p->left, q->left) && compare(p->right, q->right);
         }
         return !p && !q;
     }
};

class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
private:
    int maxPathSum(TreeNode* root, int& maxSum)
    {
        if (!root) {
            return 0;
        }
        int leftSum = std::max(0, maxPathSum(root->left, maxSum));
        int rightSum = std::max(0, maxPathSum(root->right, maxSum));
        
        int includeSum = root->val + leftSum + rightSum;
        maxSum = std::max(maxSum, includeSum);
        if (includeSum> maxSum) {
            maxSum = includeSum;
        }
        int maxChild = std::max(leftSum, rightSum);
        int returnSum = root->val + maxChild;
        return returnSum;
    }
};

int main()
{
    Solution s;
    {
        TreeNode* input(TreeNode::generate(vector<int>{1, 2, 3}));
        int ans = 6;
        assert(ans == s.maxPathSum(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{-10, 9, 20, null, null, 15, 7}));
        int ans = 42;
        assert(ans == s.maxPathSum(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, null, null, 1}));
        int ans = 48;
        assert(ans == s.maxPathSum(input));
    }
    return 0;
}