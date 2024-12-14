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
    
    vector<deque<int>> groups;
    deque<int> temp;
    bool prev = false;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool flag = num > 0;
        if(!i) prev = flag;
        if(flag != prev) {
            groups.push_back(temp);
            temp.clear();
        }
        temp.push_back(num);
        prev = flag;
    }
    groups.push_back(temp);
    
    for(int i = 0; i < groups.size() - 1; i++) {
        if(groups[i].back() > 0 && groups[i + 1].front() < 0) {
            while(groups[i].size() && groups[i + 1].size()) {
              if(groups[i].back() == groups[i + 1].front() * (-1)) {
                  groups[i].pop_back();
                  groups[i+1].pop_front();
              } else if(groups[i].back() > groups[i + 1].front() * (-1)){
                  groups[i+1].pop_front();
              } else if(groups[i].back() < groups[i + 1].front() * (-1)){
                  groups[i].pop_back();
              }
            }      
        }    
    }
    
    bool flag = false;
    for(int i = 0; i < groups.size(); i++) {
        while(groups[i].size()) {
            cout << groups[i].front() << ' ';
            groups[i].pop_front();
            flag = true;
        }
    }
    if(!flag) {
        cout <<'\n';
    }
    
    return 0;
}
