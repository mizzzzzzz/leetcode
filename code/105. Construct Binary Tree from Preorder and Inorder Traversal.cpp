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

int NullNode = 9999;
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
             nodes.emplace_back((input[i] == NullNode) ? nullptr : new TreeNode(input[i]));
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            inorderMap.emplace(inorder[i], i);
        }
        int preOrderId = 0;
        return buildTree(preorder, inorder, preOrderId, 0, n - 1);
    }
private:
    unordered_map<int, int> inorderMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inoreder, int& preOrderId, int start, int end)
    {
        if (start > end) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[preOrderId++]);
        int inorderId = inorderMap.find(node->val)->second;

        node->left = buildTree(preorder, inoreder, preOrderId, start, inorderId - 1);
        node->right = buildTree(preorder, inoreder, preOrderId, inorderId + 1, end);
        return node;
    }
};

int main()
{
    Solution s;
    {
        vector<int> pre{ 3, 9, 20 ,15 ,7 };
        vector<int> in{ 9, 3, 15, 20, 7 };
        TreeNode* ans(TreeNode::generate(vector<int>{3, 9, 20, NullNode, NullNode, 15, 7}));
        assert(TreeNode::compare(ans, s.buildTree(pre, in)));
    }
    {
        vector<int> pre{ -1 };
        vector<int> in{ -1 };
        TreeNode* ans(TreeNode::generate(vector<int>{-1}));
        assert(TreeNode::compare(ans, s.buildTree(pre, in)));
    }
    return 0;
}