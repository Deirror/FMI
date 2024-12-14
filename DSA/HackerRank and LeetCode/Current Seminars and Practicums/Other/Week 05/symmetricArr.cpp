#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        stack<int> st;
        bool flag = true;
        for(int j = 0; j < k; j++) {
            int num;
            cin >> num;
            
            if(!st.size()) {
                if(num < 0) {
                    flag = false;
                }         
                st.push(num);
                continue;
            }
            
            if(num > 0) {
                st.push(num);
            } else {
                if(st.top() == num * (-1)) {
                    st.pop();
                } else {
                    flag = false;
                }
            }
        }
        if(flag && st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
