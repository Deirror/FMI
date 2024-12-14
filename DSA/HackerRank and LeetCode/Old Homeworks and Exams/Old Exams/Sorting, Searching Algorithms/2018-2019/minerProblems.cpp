#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = int(10e4);
int arr[MAX_SIZE]{};

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    for(int i = N - 1; i > 1 ; i--) {
        int left = 0;
        int right = i - 1;
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(sum == arr[i]) {
                cout << "true";
                return 0;
            } else if(sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    cout << "false";
    return 0;
}

