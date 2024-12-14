template <class T>
int partition(T* arr, int low, int high) {
          int pivot = arr[high];                                  
          int i = low;
     
          for (int j=low; j<high; j++) {
              if (arr[j] <= pivot) {
                 swap(arr, i, j)
                 i++;
              }
          }
     
          swap(arr, i, high)
          return i;
      } 

template <class T>
void sort(T* arr, int low, int high) {
      if (low < high) {
          int pi = partition(arr, low, high);
          sort(arr, low, pi-1);
          sort(arr, pi+1, high);
      }
  }
