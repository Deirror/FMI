#include <cmath>
#include <deque>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    bool prev = false;
    deque<int> st;
    int count = 0;
    while(count < n) {
        int num;
        cin >> num;
        count++;
        
        bool flag = num < 0;
        
        if(count == 1) {
            prev = flag;
        }
        
        if(!prev && flag) {// shte ima boi
            bool end = true;
            while(st.size() && st.back() > 0 && count <= n) {
                if(st.back() == num * (-1)) {
                    st.pop_back();
                    count++;
                    if(!(cin >> num)) {
                        end = false;
                        break;
                    }                
                    if(num > 0) {
                        st.push_back(num);
                        break;
                    }   
                } else if(st.back() > num * (-1)) {
                    count++;
                    if(!(cin >> num)) {
                        end = false;
                        break;
                    }
                    if(num > 0) {
                        st.push_back(num);
                        break;
                    }   
                } else if(st.back() < num * (-1)) {
                    st.pop_back();
                }
            }
            
            if(num < 0 && end) {
                st.push_back(num);
                prev = true;
            }
        } else {
            st.push_back(num);
            prev = flag;
        }
    }
    
    while(st.size()) {
        cout << st.front() << ' ';
        st.pop_front();
    }
    
    if(!st.size()) {
        cout << '\n';
    }
    
    return 0;
}
