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
    // A utility function to store inorder traversal of tree rooted
    // with root in an array arr[]. Note that i is passed as reference
    void storeInorder(Node* root, char arr[], int& i)
    {
        if (root == NULL) {
            arr[i++] = '$';
            return;
        }
        storeInorder(root->left, arr, i);
        arr[i++] = root->key;
        storeInorder(root->right, arr, i);
    }
     
    // A utility function to store preorder traversal of tree rooted
    // with root in an array arr[]. Note that i is passed as reference
    void storePreOrder(Node* root, char arr[], int& i)
    {
        if (root == NULL) {
            arr[i++] = '$';
            return;
        }
        arr[i++] = root->key;
        storePreOrder(root->left, arr, i);
        storePreOrder(root->right, arr, i);
    }
     
    /* This function returns true if S is a subtree of T, otherwise false */
    bool isSubtree(Node* T, Node* S)
    {
        /* base cases */
        if (S == NULL)
            return true;
        if (T == NULL)
            return false;
     
        // Store Inorder traversals of T and S in inT[0..m-1]
        // and inS[0..n-1] respectively
        int m = 0, n = 0;
        char inT[MAX], inS[MAX];
        storeInorder(T, inT, m);
        storeInorder(S, inS, n);
        inT[m] = '\0', inS[n] = '\0';
     
        // If inS[] is not a substring of inT[], return false
        if (strstr(inT, inS) == NULL)
            return false;
     
        // Store Preorder traversals of T and S in preT[0..m-1]
        // and preS[0..n-1] respectively
        m = 0, n = 0;
        char preT[MAX], preS[MAX];
        storePreOrder(T, preT, m);
        storePreOrder(S, preS, n);
        preT[m] = '\0', preS[n] = '\0';
     
        // If preS[] is not a substring of preT[], return false
        // Else return true
        return (strstr(preT, preS) != NULL);
    }

private:
    bool isSubtreeRecursive(TreeNode s, TreeNode t)
    {
        if (s == null || t == null) return false;
        return IsSameTree(s, t) || IsSubtree(s.left, t) || IsSubtree(s.right, t);
    }

    bool isSameTree(TreeNode p, TreeNode q)
    {
        if (p == null)
        {
            if (q == null)
                return true;
            return false;
        }
        else if (q == null)
            return false;
        return (p.val == q.val) && IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
    }
};

int main()
{
    Solution s;
    {
        vector<vector<int>>input{ {0, 1, 0}, {1, 1, 1}, {0, 1, 0} };
        int target = 1;
        int ans = 4;
        assert(ans == s.numSubmatrixSumTarget(input, target));
    }
    {
        vector<vector<int>>input{ {1, -1}, {-1, 1} };
        int target = 0;
        int ans = 5;
        assert(ans == s.numSubmatrixSumTarget(input, target));
    }
    {
        vector<vector<int>>input{ {904} };
        int target = 0;
        int ans = 0;
        assert(ans == s.numSubmatrixSumTarget(input, target));
    }


    return 0;
}