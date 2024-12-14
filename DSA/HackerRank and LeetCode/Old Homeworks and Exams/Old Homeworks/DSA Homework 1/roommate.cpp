#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    short Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int len;
        cin >> len;
        
        short startLetter = -1;//0 P, 1 I
        int counter = 0;
        for(int j = 0; j < len; j++) {
            char ch;
            cin >> ch;
            
            if(ch == 'P') {
                if(startLetter == 0) {
                    counter++;
                }              
                startLetter = false;
            }
            else if (ch == 'I') {
                if(startLetter == 1) {
                    counter++;
                }     
                startLetter = true;
            }
        }
        cout << counter << endl;
    } 
    return 0;
}
