#include <bits/stdc++.h>
using namespace std;

long long invited[int(1e5) + 1]{};

int find_level(long long num, long long max_limit) {
    int level = 1;
    long long l = 1, r = max_limit;

    while (l < r) {
        long long fh_mid = l + (r - l) / 3;
        long long sc_mid = r - (r - l) / 3;

        if (num > fh_mid && num < sc_mid) {
            return level;
        } else if (num <= fh_mid) {
            r = fh_mid;
        } else {
            l = sc_mid;
        }

        level++;
    }
    
    return level;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p, n;
    cin >> p >> n;

    long long max_limit = pow(3, p);

    for (int i = 0; i < n; i++) {
        cin >> invited[i];
    }

    for (int i = 0; i < n; i++) {
        cout << find_level(invited[i], max_limit) << '\n';
    }

    return 0;
}
