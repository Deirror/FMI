#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 1) {
            cout << "yes\n";
            continue;
        }
        else if (m == 1 && n > 0 || m == 0) {
            cout << "no\n";
            continue;
        }

        int copyCounter = 0, normalCounter = 1;

        for (int j = 1; j < m; j++) {
            normalCounter++;
            copyCounter++;
        }

        if (copyCounter == n) cout << "yes\n";
        else if (copyCounter > n) {
            cout << "no\n";
        }
        else {
            if ((n - copyCounter) % 2 == 0) cout << "yes\n";
            else cout << "no\n";
        }
    }



    return 0;
}
