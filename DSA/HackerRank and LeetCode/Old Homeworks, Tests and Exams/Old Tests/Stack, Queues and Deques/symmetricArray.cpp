#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <stack>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    while(n--) {
        int k;
        cin >> k;
        stack<int> st;
        while(k--) {
            int x;
            cin >> x;
            if(st.empty()) {
                st.push(x);
            } else if(st.top() == (-1)*x && st.top() > 0) {
                st.pop();
            } else {
                st.push(x);
            }
        }
        if(st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
