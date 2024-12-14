#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[int(10e6)];
int copyArr[int(10e6)];

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        copyArr[i] = arr[i];
    }
    
    sort(copyArr, copyArr + n);
    
    int left = 0, right = n - 1;
    
    bool leftFlag = true, rightFlag = true;
    while(left < right && (leftFlag || rightFlag)) {
        if(arr[left] == copyArr[left]) {
            left++;
        } else {
            leftFlag = false;
        }
        
        if(arr[right] == copyArr[right]) {
            right--;
        }
        else {
            rightFlag = false;
        }
    }
    
    if(left >= right) cout << 0;
    else cout << right - left + 1;
    
    return 0;
}
