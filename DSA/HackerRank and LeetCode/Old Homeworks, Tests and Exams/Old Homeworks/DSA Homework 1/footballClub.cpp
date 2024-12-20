#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[int(10e5)];

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 0, j = 1; i < N; i++) {

        if (arr[i] > 0) {
            bool isInArr = false;
            while (arr[i] == j) {
                i++;
                isInArr = true;
            }

            if (isInArr) {
                j++;
                i--;
            }
            else {
                cout << j;
                break;
            }
        }

        if (i + 1 == N) {
            cout << j;
        }
    }

    return 0;
}
