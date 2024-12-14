template <class T>
bool binarySearch(T* arr, size_t low, size_t high, const T& searched) {
    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == searched) {
            return true;
        }

        if(arr[mid] < searched) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return -1;
}
