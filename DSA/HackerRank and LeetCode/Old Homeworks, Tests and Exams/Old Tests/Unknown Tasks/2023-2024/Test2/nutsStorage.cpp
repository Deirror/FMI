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

int my_binary_search(pair<int,int>* arr, int n, int searched, int idx_excld) {
    int l = 0;
    int r = n - 1;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        
        if(arr[mid].first == searched && idx_excld != mid) {
            return mid;
        } else if(arr[mid].first < searched) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int x, n;
        cin >> x >> n;
        pair<int, int> arr[n];
        
        for(int j = 0; j < n; j++) {
            cin >> arr[j].first;
            arr[j].second = j + 1;
        }
        
        sort(arr, arr + n);
        
        for(int j = 0; j < n; j++) {
            int idx = my_binary_search(arr, n, abs(x - arr[j].first), j);
            if(idx != -1) {
                cout << min(arr[j].second, arr[idx].second) << ' ' << max(arr[j].second, arr[idx].second) << '\n';
                break;
            }
        }
    }
    return 0;
}
