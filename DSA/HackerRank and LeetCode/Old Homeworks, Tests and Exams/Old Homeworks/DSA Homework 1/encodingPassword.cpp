#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string password;
    cin >> password;
    
    char ch = password[0];
    int counter = 0;
    for(int i = 0; i < password.length(); i++) {
        if(password[i] == ch) {
            counter++;
        } 
        else {
            cout << counter << ch;
            ch = password[i];
            counter = 1;
        }
    }
    cout << counter << ch;
    return 0;
}
