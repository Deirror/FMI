#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

long long dp[int(1e3) + 1][int(1e3) + 1];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dp[i][j];
        }
    }
    int k;
    cin >> k;
    set<pair<int, int>> us;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        us.insert(pair<int,int>(x, y));
    }
    for(int i = 1; i < n; i++) {
        dp[i][0] += dp[i - 1][0];
        dp[0][i] += dp[0][i - 1];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            long long maxNormalCond = max(dp[i][j - 1], dp[i - 1][j]);
            if(us.find(pair<int,int>(i, j)) != us.end()) {
                dp[i][j] += max(maxNormalCond, dp[i - 1][j - 1]);
            } else {
                dp[i][j] += maxNormalCond;
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}
