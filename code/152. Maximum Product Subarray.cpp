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
    int findMin(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        while (end > start) {
            if (nums[start] < nums[end]) {
                return nums[start];
            }
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[start]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return nums[start];
    }
};

int main()
{
    Solution s;
    {
        vector<int> input{ 2, 1 };
        int ans = 1;
        assert(ans == s.findMin(input));
    }
    {
        vector<int> input{ 1 };
        int ans = 1;
        assert(ans == s.findMin(input));
    }
    {
        vector<int> input{ 3,4,5,1,2 };
        int ans = 1;
        assert(ans == s.findMin(input));
    }
    {
        vector<int> input{ 4,5,6,7,0,1,2 };
        int ans = 0;
        assert(ans == s.findMin(input));
    }
    {
        vector<int> input{ 11,13,15,17 };
        int ans = 11;
        assert(ans == s.findMin(input));
    }
    return 0;
}