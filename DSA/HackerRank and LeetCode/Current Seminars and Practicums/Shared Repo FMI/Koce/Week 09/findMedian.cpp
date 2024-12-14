class MedianFinder {
public:
    // Min-heap for the larger half of the numbers
    priority_queue<int, std::vector<int>, std::greater<int>> minHeapForLargeNum;
    // Max-heap for the smaller half of the numbers
    priority_queue<int> maxHeapForSmallNum;

    MedianFinder() {
        // No need for explicit initialization as the heaps are already
        // initialized
    }

    void addNum(int num) {
        if (maxHeapForSmallNum.empty() || maxHeapForSmallNum.top() >= num) {
            maxHeapForSmallNum.push(num);
        } else {
            minHeapForLargeNum.push(num);
        }

        // Balance the heaps
        if (maxHeapForSmallNum.size() > minHeapForLargeNum.size() + 1) {
            minHeapForLargeNum.push(maxHeapForSmallNum.top());
            maxHeapForSmallNum.pop();
        } else if (maxHeapForSmallNum.size() < minHeapForLargeNum.size()) {
            maxHeapForSmallNum.push(minHeapForLargeNum.top());
            minHeapForLargeNum.pop();
        }
    }

    double findMedian() {
        if (maxHeapForSmallNum.size() == minHeapForLargeNum.size()) {
            return (maxHeapForSmallNum.top() / 2.0) +
                   (minHeapForLargeNum.top() / 2.0);
        } else {
            return maxHeapForSmallNum.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
