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

// https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode* head)
    {
        if (!head) {
            return false;
        }
        ListNode* turtle = head;
        ListNode* rabbit = head;
        do {
            turtle = turtle->next;
            for (int i = 0; i < 2; ++i) {
                rabbit = rabbit->next;
                if (!rabbit) {
                    return false;
                }
            }
        } while (turtle != rabbit);
        return true;
    }
};

int main()
{
    Solution s;
    {
        ListNode* input = ListNode::generate({ 3,2,0,-4 });
        int pos = 1;
        input->linkLast(pos);
        bool ans = true;
        assert(ans == s.hasCycle(input));
    }
    {
        ListNode* input = ListNode::generate({ 1,2 });
        int pos = 0;
        input->linkLast(pos);
        bool ans = true;
        assert(ans == s.hasCycle(input));
    }
    {
        ListNode* input = ListNode::generate({ 1 });
        int pos = -1;
        input->linkLast(pos);
        bool ans = false;
        assert(ans == s.hasCycle(input));
    }

    return 0;
}