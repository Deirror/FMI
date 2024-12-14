#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll merge_and_count(vector<int>& arr, int left, int mid, int right) {
    vector<int> left_arr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> right_arr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    ll inversions = 0;

    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k++] = left_arr[i++];
        } else {
            arr[k++] = right_arr[j++];
            inversions += left_arr.size() - i;
        }
    }
    
    while (i < left_arr.size()) arr[k++] = left_arr[i++];
    while (j < right_arr.size()) arr[k++] = right_arr[j++];

    return inversions;
}

ll merge_sort_and_count(vector<int>& arr, int left, int right) {
    ll inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        inversions += merge_sort_and_count(arr, left, mid);
        inversions += merge_sort_and_count(arr, mid + 1, right);
        inversions += merge_and_count(arr, left, mid, right);
    }
    return inversions;
}

int main() {
    int Q;
    cin >> Q;
    
    while (Q--) {
        int N;
        cin >> N;
        vector<int> soldiers(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> soldiers[i];
        }
        
        ll result = merge_sort_and_count(soldiers, 0, N - 1);

        cout << result << endl;
    }
    
    return 0;
}
