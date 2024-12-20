#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int lowerBound(int arr[], int N, int X) {
    int low = 0;
    int high = N;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (X <= arr[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}

const int MAX_SIZE = int(10e5);
int arr[MAX_SIZE];
int copyArr[MAX_SIZE];
vector<int> hist(MAX_SIZE + 1, -1);

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        copyArr[i] = arr[i];
    }

    sort(copyArr, copyArr + n);

    for (int i = 0; i < n; i++) {
        if (hist[arr[i]] == -1) {
            int pos = lowerBound(copyArr, n, arr[i]);
            hist[arr[i]] = distance(copyArr, copyArr + pos);
        }
        else {
            hist[arr[i]]++;
        }

        cout << hist[arr[i]] << ' ';
    }

    return 0;
}
