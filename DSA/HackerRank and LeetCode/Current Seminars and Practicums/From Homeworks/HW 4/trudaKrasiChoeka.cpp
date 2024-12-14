#include <cmath>
#include <deque>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    deque<int> dq;
    vector<int> res;
    for(int i = 0; i < n; i++) {
        while(dq.size() && arr[i] < arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if(dq.front() <= i - k) {
            dq.pop_front();
        }
        
        if(i >= k - 1) {
            res.push_back(arr[dq.front()]);
        }
    }
    
    long long sum = 0;
    for(auto num : res) {
        sum += num;
    }
    cout << sum;
    
    return 0;
}
