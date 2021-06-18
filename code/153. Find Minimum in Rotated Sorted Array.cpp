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
    int maxProduct(vector<int>& nums)
    {
        int ans = nums[0];
        int pos = nums[0];
        int neg = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            int p = pos;
            pos = std::max(nums[i], std::max(pos * nums[i], neg * nums[i]));
            neg = std::min(nums[i], std::min(p * nums[i], neg * nums[i]));
            if (pos > ans) {
                ans = pos;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ -2, 3, -4 };
        int ans = 24;
        assert(ans = s.maxProduct(input));
    }
    {
        vector<int> input{ 2,3,-2,4 };
        int ans = 6;
        assert(ans = s.maxProduct(input));
    }
    {
        vector<int> input{ 2,0,1 };
        int ans = 0;
        assert(ans = s.maxProduct(input));
    }
    return 0;
}