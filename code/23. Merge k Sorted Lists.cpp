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
        if (a && !b) {
            return false;
        }
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) {
            return nullptr;
        }
        int interval = 1;
        int length = lists.size();

        while (interval < length) {
            for (int i = 0; i < length - interval; i += interval * 2) {
                merge(lists, i, i + interval);
            }
            interval *= 2;
        }
        return lists[0];
    }
private:
    void merge(vector<ListNode*>& lists, int i, int j)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;

        ListNode* l1 = lists[i];
        ListNode* l2 = lists[j];
        while (l1 || l2) {
            if (!l1) {
                ptr->next = l2;
                break;
            } else if (!l2) {
                ptr->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else  {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        lists[i] = dummy->next;
    }
};

int main()
{
    Solution s;
    {
        ListNode* input1 = ListNode::generate({ 1,4,5 });
        ListNode* input2 = ListNode::generate({ 1,3,4 });
        ListNode* input3 = ListNode::generate({ 2,6 });
        vector<ListNode*> lists{ { input1,input2,input3 } };
        ListNode* ans = ListNode::generate({ 1,1,2,3,4,4,5,6 });
        ListNode* output = s.mergeKLists(lists);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    {
        vector<ListNode*> lists{};
        ListNode* ans = ListNode::generate({});
        ListNode* output = s.mergeKLists(lists);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    {
        ListNode* input1 = ListNode::generate({});
        vector<ListNode*> lists{ { input1 } };
        ListNode* ans = ListNode::generate({});
        ListNode* output = s.mergeKLists(lists);
        assert(ListNode::compare(ans, output));
        ListNode::remove(ans);
        ListNode::remove(output);
    }
    return 0;
}