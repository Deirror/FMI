template <class T>
void selectionSort(T* arr, size_t size) {

  for(int i = 0; i < size; i++) {
      int minIdx = i;
      for(int j = i + 1; j < size; j++) {
          if(arr[minIndx] > arr[j]) {
              minIdx = j;
          }
      }

    if(minIndx != i) {
        std::swap(arr[minIdx], arr[i]);
    }
  }
}
