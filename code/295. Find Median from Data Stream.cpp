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

class MaxHeap
{
public:
    MaxHeap() {}

    void push(int n)
    {
        v.emplace_back(n);
        siftup();
    }

    int front()
    {
        return v.front();
    }

    int pop()
    {
         int f = v.front();
         std::swap(v.front(), v.back());
         v.pop_back();
         siftdown();
         return f;
    }

    size_t size()
    {
        return v.size();
    }

    void siftup()
    {
        int i = v.size() - 1;
        while (i >= 0) {
            int parent = (i - 1) / 2;
            if (v[parent] >= v[i]) {
                break;
            }
            std::swap(v[parent], v[i]);
            i = parent;
        }
    }

    void siftdown()
    {
        int i = 0;
        while (i < v.size()) {
            int left = 2 * i + 1;
            if (left >= v.size()) {
                break;
            }
            int maxChild = left;
            int right = 2 * i + 2;
            if (right < v.size() && v[right] > v[left]) {
                maxChild = right;
            }
            if (v[maxChild] < v[i]) {
                break;
            }
            std::swap(v[maxChild], v[i]);
            i = maxChild;
        }
    }

private:
    vector<int> v;
};

class MinHeap
{
public:
    MinHeap() {}

    void push(int n)
    {
        maxHeap.push(-1 * n);
    }

    int front()
    {
        return -1 * maxHeap.front();
    }

    int pop()
    {
        return -1 * maxHeap.pop();
    }

    size_t size()
    {
        return maxHeap.size();
    }

private:
    MaxHeap maxHeap;
};

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        int m = maxHeap.size();
        int n = minHeap.size();
        if (m == 0) {
            maxHeap.push(num);
        } else if (m == n) {
            if (num < minHeap.front()) {
                maxHeap.push(num);
            } else {
                int f = minHeap.pop();
                minHeap.push(num);
                maxHeap.push(f);
            }
        } else if (m > n) {
            if (num > maxHeap.front()) {
                minHeap.push(num);
            } else {
                int f = maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(f);
            }
        }
    }

    double findMedian()
    {
        int m = maxHeap.size();
        int n = minHeap.size();
        if (m == n) {
            return (static_cast<long long>(maxHeap.front()) + static_cast<long  long>(minHeap.front())) / 2.0;
        } else {
            return maxHeap.front();
        }
    }

private:
    MaxHeap maxHeap;
    MinHeap minHeap;
};

int main()
{
    {
        MedianFinder f;
        f.addNum(1);
        f.addNum(2);
        assert(1.5 == f.findMedian());
        f.addNum(3);
        assert(2.0 == f.findMedian());
    }
    return 0;
}