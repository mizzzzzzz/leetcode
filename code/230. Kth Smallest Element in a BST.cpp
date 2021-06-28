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

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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

class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        if (!root) {
            return 0;
        }
        int count = 0;
        return kthSmallest(root, k, count);
    }
private:
    int kthSmallest(TreeNode* root, int k, int& count)
    {
        if (root->left) {
            int ret = kthSmallest(root->left, k, count);
            if (ret != -1) {
                return ret;
            }
        }
        if (++count == k) {
            return root->val;
        }
        if (root->right) {
            return kthSmallest(root->right, k, count);
        }
        return -1;
    }
};

int main()
{
    Solution s;
    {
        TreeNode* input(TreeNode::generate(vector<int>{3, 1, 4, -1, 2}));
        int k = 1;
        int ans = 1;
        assert(ans == s.kthSmallest(input, k));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{5, 3, 6, 2, 4, -1, -1, 1}));
        int k = 3;
        int ans = 3;
        assert(ans == s.kthSmallest(input, k));
    }
    return 0;
}