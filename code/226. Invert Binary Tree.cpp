#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using std::pair;
using std::queue;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;


class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) {
            return nullptr;
        }
        TreeNode* left = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left);
        return root;
    }
};