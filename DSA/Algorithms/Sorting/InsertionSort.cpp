template <class T>
void insertionSort(T* arr, size_t size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key]) {
            arr[j+1] = arr[j];
            j--;
        }
      arr[j + 1] = key;
    }
}
