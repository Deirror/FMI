# Sorting

| Algorithm | Best Time Complexity | Avarage Time Complexity | Worst Time Complexity | Space Complexity | Comparisions | Swaps | Stable | Local | In-Place |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Bubble Sort | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | Yes | Yes | Yes |
| Selection Sort | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | O(n<sup>2</sup>) | O(n) | No | No | Yes |
| Insertion Sort | O(n) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | O(n<sup>2</sup>) | O(n) | Yes | Yes | Yes |
| Merge Sort | O(n*log(n)) | O(n*log(n)) | O(n*log(n)) | O(n) | O(n*log(n)) | O(n*log(n)) | Yes | No | No |
| Quick Sort | O(n) | O(n*log(n)) | O(n<sup>2</sup>) | O(n) | O(n*log(n)) | O(n*log(n)) | No | Yes | Yes |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(n + k) | O(1) | O(1) | Yes | Yes | No |

Notes
---

-  Selection Sort is the worst here
-  Insertion Sort for almost sorted arrays
-  Quick Sort for small arrays
-  Merge Sort for larger arrays
-  Counting Sort is fastest, but most concrete  

# Searching

| Algorithm | Best Time Complexity | Avarage Time Complexity | Worst Time Complexity |  
| --- | --- | --- | --- |
| Linear Search | O(1) | O(n) | O(n) |
| Binary Search | O(1) | O(log(n)) | O(log(n)) |
| Trinary Search | O(1) | O(log<sub>3</sub>(n)) | O(log<sub>3</sub>(n)) |
| Jump Search | O(1) | O(sqrt(n)) | O(sqrt(n)) |

# Linked Lists

Linked List vs Array
---

| Operation | Array | Linked List | Doubly Linked List | 
| --- | --- | --- | --- |
| push_front | O(n) | O(1) | O(1) |
| pop_front | O(n) | O(1) | O(1) |
| push_back | O(1*) | O(1) | O(1) |
| pop_back | O(1) | O(n) | O(1) |
| get_front/end | O(1) | O(1) | O(1) |
| get_at | O(1) | O(n) | O(n) |
| find_key | O(n) | O(n) | O(n) |
| erase_key | O(n) | O(n) | O(n) |
