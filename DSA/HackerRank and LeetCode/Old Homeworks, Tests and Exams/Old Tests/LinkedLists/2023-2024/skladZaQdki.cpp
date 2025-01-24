#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int bs(vector<pair<int, int>>& arr, int searched, int excl_idx) {
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid].first == searched && arr[mid].second != excl_idx) {
            return arr[mid].second;
        }
        
        if(arr[mid].first < searched) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--) {
        int x, n;
        cin >> x >> n;
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) {
            int w;
            cin >> w;
            arr[i] = make_pair(w, i + 1); 
        }
        sort(arr.begin(), arr.end());
        for(auto& pr : arr) {
            int idx = bs(arr, x - pr.first, pr.second);
            if(idx == -1) {
                continue;
            }          
            cout << min(pr.second, idx) << ' ' << max(pr.second, idx) << '\n';
            break;
        }
    }
    return 0;
}
