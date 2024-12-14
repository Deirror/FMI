#include <queue>
#include <vector>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        // Initialize the min-heap
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        // If the heap has fewer than k elements, add the new value
        if (minHeap.size() < k) {
            minHeap.push(val);
        }
        // If the new value is greater than the smallest in the heap, replace it
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }

        // The top of the min-heap is the k-th largest element
        return minHeap.top();
    }

private:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        minHeap; // Min-heap
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
