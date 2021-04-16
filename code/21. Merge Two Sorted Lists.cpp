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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while (l1) {
            cur->next = new ListNode(l1->val);
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2) {
            cur->next = new ListNode(l2->val);
            cur = cur->next;
            l2 = l2->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    {
        ListNode* input1 = ListNode::generate({ 1,2,4 });
        ListNode* input2 = ListNode::generate({ 1,3,4 });
        ListNode* ans = ListNode::generate({ 1,1,2,3,4,4 });
        ListNode* output = s.mergeTwoLists(input1,input2);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    {
        ListNode* input1 = ListNode::generate({});
        ListNode* input2 = ListNode::generate({});
        ListNode* ans = ListNode::generate({});
        ListNode* output = s.mergeTwoLists(input1, input2);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    {
        ListNode* input1 = ListNode::generate({});
        ListNode* input2 = ListNode::generate({0});

        ListNode* ans = ListNode::generate({0});
        ListNode* output = s.mergeTwoLists(input1, input2);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    {
        ListNode* input1 = ListNode::generate({-9, 3});
        ListNode* input2 = ListNode::generate({5, 7 });

        ListNode* ans = ListNode::generate({ -9, 3, 5, 7 });
        ListNode* output = s.mergeTwoLists(input1, input2);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    return 0;
}