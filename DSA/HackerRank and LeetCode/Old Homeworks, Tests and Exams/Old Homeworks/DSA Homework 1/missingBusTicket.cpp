#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nums[int(10e5)];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    bool flag = false;
    for (int i = 0, j = 1; i < N; i++) {
        if (nums[i] > 0) {
            if (nums[i] != j) {
                if (flag) j++;
               
                if (nums[i] != j) {
                    cout << j;
                    return 0;
                }
            }
        }
               flag = true;
    }

    cout << nums[N - 1] + 1;

    return 0;
}
