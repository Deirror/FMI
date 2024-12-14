//Also could be interpreted as AcceleratedSearch
template <class T>
int linearSearch(T* arr, size_t size, const T& searched) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == searched) {
            return i;
        }  
    } 
    return -1;
}
