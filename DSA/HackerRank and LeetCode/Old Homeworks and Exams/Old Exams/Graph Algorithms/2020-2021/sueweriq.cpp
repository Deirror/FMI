#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int MAX_SIZE = 2001;
vector<vector<unordered_set<int>>> edgeWeightMatrix(MAX_SIZE, vector<unordered_set<int>>(MAX_SIZE));
unordered_set<int> superstitiousIntegers;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edgeWeightMatrix[x][y].insert(w);
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int num;
        cin >> num;
        superstitiousIntegers.insert(num);
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int l;
        cin >> l;
        int f;
        cin >> f;
        bool flag = true;
        for(int j = 1; j < l; j++) {
            int c;
            cin >> c;
            bool omg = false;
            for(auto w : edgeWeightMatrix[f][c]) {
                if(superstitiousIntegers.find(w) == superstitiousIntegers.end()) {
                    omg = true;
                    break;
                }
            }
            if(!omg) {         
                flag = false;
                j++;
                while(j < l) {
                    cin >> c;
                    j++;
                }
                break;
            }
            f = c;
        }
        cout << flag;
    }
    return 0;
}
