#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    stack<int> stSum;
    stack<int> stUR;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num >= 0) {
            stSum.push(num);
        } else if(num == -1) {
            if(stSum.size()) {
            stUR.push(stSum.top());
            stSum.pop();
            }
        } else if(num == -2) {
            if(stUR.size()) {
            stSum.push(stUR.top());
            stUR.pop();
            }
        }
    }
    
    int sum = 0;
    while(stSum.size()) {
        sum += stSum.top();
        stSum.pop();
    }
    cout << sum;
    return 0;
}
