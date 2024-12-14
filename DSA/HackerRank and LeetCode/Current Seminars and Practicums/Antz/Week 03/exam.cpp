#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long f(long long x) {
	return x * (x + 1) / 2;
}

bool check(long long n, long long F, long long test) {
	return f(test) - f(F - 1) >= n;
}

int main()
{
	long long n = 0;
	int k = 0;
	cin >> n >> k;

	long long left = 0;
	long long right = LONG_MAX;

	long long res = LONG_MAX;

	while (left <= right) {
		long long mid = left + (right - left) / 2;

		if (check(n, k, mid)) {
			res = min(res, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << res - k + 1;

	return 0;
}
