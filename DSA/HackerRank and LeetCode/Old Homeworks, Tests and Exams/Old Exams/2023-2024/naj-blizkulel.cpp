#include <bits/stdc++.h>
using namespace std;

int arr[int(1e6) + 1];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = n - 1; i >= 0; i--) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int num;
        cin >> num;
        auto it = lower_bound(arr, arr + n, num);
        it = it + 1;
        if(it >= arr + n) {
            cout << -1 << '\n';
        } else {
            int val = *it;
            if(*(it - 1) != num) {
                int fDiff = (*(it - 1) - num);
                int sDiff = INT_MAX;
                if(it - 2 >= arr) {
                  sDiff =(num - *(it - 2));
                }
                if(fDiff != sDiff) {
                    val = (fDiff < sDiff ? *it : *(it - 1));
                }        
            }
            cout << val << '\n';
        }
    }

    return 0;
}
