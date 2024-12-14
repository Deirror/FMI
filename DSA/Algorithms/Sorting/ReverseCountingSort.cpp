void reverse_counting_sort(char* str, int n) {
	char* copy_str = new char[n] {};

	for (int i = 0; i < n; i++) {
		copy_str[i] = str[i];
	}

	int histogram[256]{};
	for (int i = 0; i < n; i++) {
		histogram[str[i]]++;
	}

	for (int i = 1; i < 256; i++) {
		histogram[i] += histogram[i - 1];
	}

	for (int i = 255; i >= 0; i--) {
		histogram[i] = std::abs(histogram[i] - n);
	}

	for (int i = n - 1; i >= 0; i--) {
		str[histogram[copy_str[i]]++] = copy_str[i];
	}
}
