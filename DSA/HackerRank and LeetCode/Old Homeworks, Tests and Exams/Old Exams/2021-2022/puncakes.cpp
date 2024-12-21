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

bool is_min_time(long long* arr, long long n, long long time, long long goal) {
    long long result = 0;
    
    for(int i = 0; i < n; i++) {
        result += time / arr[i]; 
    }
    
    return result >= goal;
}

int main() {
    unsigned long long n;
    int k;
    cin >> n >> k;
    
    long long min_time = 0;
    long long max_time = 0;
    
    long long time_per_pancake_arr[k];
    for(int i = 0; i < k; i++) {
        cin >> time_per_pancake_arr[i];
        
        min_time = min(min_time, (time_per_pancake_arr[i]));
        max_time = max(max_time, (time_per_pancake_arr[i]));    
    }
    
    long long best_case = (n / k) * min_time;
    long long worst_case = (n / k + 1) * max_time;
    
    long long result = 0;
    
    while(best_case <= worst_case) {
        long long mid_case = best_case + (worst_case - best_case) / 2;
        
        if(is_min_time(time_per_pancake_arr, k, mid_case, n)) {
            result = mid_case;
            worst_case = mid_case - 1;
        } else {
            best_case = mid_case + 1;
        }
    }
    
    cout << result;
    
    return 0;
}
