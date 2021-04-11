#include <cassert>
#include <vector>
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

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
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* nthNext = head;
        for (int i = 1; i <= n; ++i) {
            nthNext = nthNext->next;
        }
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (nthNext) {
            prev = cur;
            cur = cur->next;
            nthNext = nthNext->next;
        }
        if (cur == head) {
            ListNode* newHead = head->next;
            delete cur;
            return newHead;
        } else {
            prev->next = cur->next;
            delete cur;
            return head;
        }
    }
};

int main()
{
    Solution s;
    {
        ListNode* input = ListNode::generate({ 1,2,3,4,5 });
        ListNode* ans = ListNode::generate({ 1,2,3,5 });
        ListNode* output = s.removeNthFromEnd(input, 2);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    {
        ListNode* input = ListNode::generate({ 1 });
        ListNode* ans = ListNode::generate({ });
        ListNode* output = s.removeNthFromEnd(input, 1);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    {
        ListNode* input = ListNode::generate({ 1,2 });
        ListNode* ans = ListNode::generate({ 1 });
        ListNode* output = s.removeNthFromEnd(input, 1);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    return 0;
}