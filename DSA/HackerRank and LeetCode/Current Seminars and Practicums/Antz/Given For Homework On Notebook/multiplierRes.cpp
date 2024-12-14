#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001]{};
int res[1001]{};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		res[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		res[0] = (res[0] * arr[i]) % (int(10e8) + 1);
	}

	for (int i = 1; i < n; i++) {
		res[i] = (res[i - 1] * (arr[i - 1]) / (arr[i])) % (int(10e8) + 1);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}

	return 0;
}
