#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
    // on the right side from median
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // on the left side from median
    priority_queue<int> maxHeap;
    
    void addNum(int num) {
        if(minHeap.size() == 0 || minHeap.top() < num) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }
        
        // move from one to the other
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    MedianFinder mf;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        mf.addNum(num);
        cout << fixed << setprecision(1) << double(mf.findMedian()) << '\n';
    }
    return 0;
}
