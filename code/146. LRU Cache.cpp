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

class LRUCache
{
public:
    struct DLQueue
    {
        int key;
        int val;
        DLQueue* prev;
        DLQueue* next;
    };

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new DLQueue();;
        tail = new DLQueue();
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache()
    {
        delete head;
        delete tail;
    }

    int get(int key)
    {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        DLQueue* node = it->second;
        addToTail(node);
        return node->val;
    }

    void put(int key, int value)
    {
        auto it = m.find(key);
        if (it != m.end()) {
            DLQueue* node = it->second;
            node->val = value;
            addToTail(node);
            return;
        }
        if (m.size() == capacity) {
            DLQueue* node = head->next;
            head->next = node->next;
            node->next->prev = head;
            m.erase(node->key);
            delete node;
        }
        DLQueue* node = new DLQueue();
        node->key = key;
        node->val = value;

        addToTail(node);
        m.emplace(key, node);
    }

    void addToTail(DLQueue* node)
    {
        if (node->next == tail) {
            return;
        }
        if (node->prev) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        DLQueue* prev = tail->prev;
        prev->next = node;
        node->next = tail;
        node->prev = prev;
        tail->prev = node;
    }

private:

    int capacity;
    unordered_map<int, DLQueue*> m;
    DLQueue* head;
    DLQueue* tail;
};

int main()
{
    {
        LRUCache c(1);
        c.put(2, 1);
        assert(1 == c.get(2));
        c.put(3, 2);
        assert(-1 == c.get(2));
        assert(2 == c.get(3));
    }
    {
        LRUCache c(2);;
        c.put(1, 1);
        c.put(2, 2);
        assert(1 == c.get(1));
        c.put(3, 3);
        assert(-1 == c.get(2));
        c.put(4, 4);
        assert(-1 == c.get(1));
        assert(3 == c.get(3));
        assert(4 == c.get(4));        
    }
    {
        LRUCache c(2);
        c.put(1, 0);
        c.put(2, 2);
        assert(0 == c.get(1));
        c.put(3, 3);
        assert(-1 == c.get(2));
        c.put(4, 4);
        assert(-1 == c.get(1));
        assert(3 == c.get(3));
        assert(4 == c.get(4));
    }
    return 0;
}