#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::queue;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// https://leetcode.com/problems/reorder-list/
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    static ListNode* generate(vector<int> input)
    {
        if (input.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(input.back());
        for (int i = input.size() - 2; i >= 0; --i) {
            head = new ListNode(input[i], head);
        }
        return head;
    }

    static bool compare(ListNode* a, ListNode* b)
    {
        while (a && b) {
            if (a->val != b->val) {
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return true;
    }

    static void remove(ListNode* a)
    {
        while (a) {
            ListNode* next = a->next;
            delete a;
            a = next;
        }
    }

    void linkLast(int id)
    {
        if (id == -1) {
            return;
        }
        int count = 0;
        ListNode* to = this;
        while (count < id) {
            to = to->next;
            ++count;
        }

        ListNode* last = this;
        while (last->next) {
            last = last->next;
        }
        last->next = to;
    }
};

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if (!head) {
            return;
        }

        stack<ListNode*> s;
        ListNode* ptr = head;
        while (ptr) {
            s.emplace(ptr);
            ptr = ptr->next;
        }

        ptr = head;
        while (!s.empty()) {
            ListNode* top = s.top();
            s.pop();
            ListNode* next = ptr->next;
            if (ptr == top) {
                ptr->next = nullptr;
                break;
            }
            if (ptr->next == top) {
                ptr->next->next = nullptr;
                break;
            }
            ptr->next = top;
            top->next = next;
            ptr = next;
        }
    }
};

int main()
{
    Solution s;
    {
        ListNode* input = ListNode::generate({ 1,2,3,4 });
        ListNode* ans = ListNode::generate({ 1,4,2,3 });
        s.reorderList(input);
        assert(ListNode::compare(ans, input));
    }
    {
        ListNode* input = ListNode::generate({ 1,2,3,4,5 });
        ListNode* ans = ListNode::generate({ 1,5,2,4,3 });
        s.reorderList(input);
        assert(ListNode::compare(ans, input));
    }

    return 0;
}