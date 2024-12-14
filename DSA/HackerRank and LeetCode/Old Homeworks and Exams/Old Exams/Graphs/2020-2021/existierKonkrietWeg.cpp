#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    unordered_set<int> graph[1001];
    for(int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        for(int j = 0; j < ni; j++) {
            int cv;
            cin >> cv;
            graph[i].insert(cv);
            graph[cv].insert(i);
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int lj;
        cin >> lj;
        int f;
        cin >> f;
        bool flag = true;
        for(int j = 1; j < lj; j++) {
            int c;
            cin >> c;
            //cout << '(' << f << " - " << c << ')' << ' '; 
            if(graph[f].find(c) == graph[f].end()) {
                 j++;
                while(j < lj) {
                    j++;
                    f = c;
                    cin >> c;
                    //cout << '(' << f << " - " << c << ')' << ' '; 
                }
                flag = false;
                break;
            }
            f = c;
        }
        if(flag) {
            cout << '1' << ' ';
        } else {
            cout << '0' << ' ';
        }
        //cout << '\n';
    }
    return 0;
}
