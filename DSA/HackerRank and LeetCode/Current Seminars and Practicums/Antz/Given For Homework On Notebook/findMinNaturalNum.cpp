#include <iostream>
#include <algorithm>
using namespace std;
int hist[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if(num >= 0)
		hist[num]++;
	}

	int min = 0;
	for (int i = 0; i <= 1000; i++) {
		if (i > min) {
			break;
		}

		if (hist[i] >= 1) {
			min++;
		}
	}

	std::cout << min;

	return 0;
}
