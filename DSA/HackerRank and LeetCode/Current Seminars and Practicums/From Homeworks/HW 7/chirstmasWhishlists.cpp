#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int MAX_TIME = 10080;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> dp(MAX_TIME + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = MAX_TIME; j >= A[i]; --j) {
            dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
        }
    }

    int result = 0;
    for (int j = 0; j <= MAX_TIME; ++j) {
        result = (result + dp[j]) % MOD;
    }

    cout << result << endl;
    return 0;
}
