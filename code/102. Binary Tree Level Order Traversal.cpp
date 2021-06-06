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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        stack<pair<int, TreeNode*>> s;
        s.emplace(0, root);
        while (!s.empty()) {
            auto entry = s.top();
            s.pop();
            if (ans.size() <= entry.first) {
                ans.emplace_back(vector<int>());
            }
            ans[entry.first].emplace_back(entry.second->val);
            if (entry.second->right) {
                s.emplace(entry.first + 1, entry.second->right);
            }
            if (entry.second->left) {
                s.emplace(entry.first + 1, entry.second->left);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        TreeNode* input(TreeNode::generate(vector<int>{}));
        vector<vector<int>> ans{};
        assert(ans == s.levelOrder(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{}));
        vector<vector<int>> ans{};
        assert(ans == s.levelOrder(input));
    }
    {
        TreeNode* input(TreeNode::generate(vector<int>{3, 9, 20, -1, -1, 15, 7}));
        vector<vector<int>> ans{ {3}, {9, 20}, {15, 7} };
        assert(ans == s.levelOrder(input));
    }
    return 0;
}