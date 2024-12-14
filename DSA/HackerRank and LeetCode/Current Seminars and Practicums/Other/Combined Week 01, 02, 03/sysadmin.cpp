#include <iostream>
using namespace std;

bool check(int* arr, int n, int test, int goal) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		count += arr[i] / test;
	}

	return count >= goal;
}

int arr[int(1e5)];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 1;
	int right = int(1e9);

	int res = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (check(arr, n, mid, k)) {
			res = max(res, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << res;
	return 0;
}
