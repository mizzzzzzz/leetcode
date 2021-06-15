#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::queue;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        if (!node) {
            return nullptr;
        }
        Node* clone[101] = { nullptr };
        queue<Node*> s;
        s.emplace(node);
        while (!s.empty()) {
            Node* n = s.front();
            if (!clone[n->val]) {
                clone[n->val] = new Node(n->val);
            }
            for (Node* nb : n->neighbors) {
                if (!clone[nb->val]) {
                    clone[nb->val] = new Node(nb->val);
                    s.emplace(nb);
                }
                clone[n->val]->neighbors.emplace_back(clone[nb->val]);
            }
            s.pop();
        }
        return clone[1];
    }
};

int main()
{
    Solution s;
    return 0;
}