# Sorting

| Algorithm | Best Time Complexity | Avarage Time Complexity | Worst Time Complexity | Space Complexity | Comparisons | Swaps | Stable | Local | In-Place |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Bubble Sort | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | Yes | Yes | Yes |
| Selection Sort | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | O(n<sup>2</sup>) | O(n) | No | No | Yes |
| Insertion Sort | O(n) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | O(n<sup>2</sup>) | O(n) | Yes | Yes | Yes |
| Merge Sort | O(n*log(n)) | O(n*log(n)) | O(n*log(n)) | O(n) | O(n*log(n)) | O(n*log(n)) | Yes | No | No |
| Quick Sort | O(n) | O(n*log(n)) | O(n<sup>2</sup>) | O(n) | O(n*log(n)) | O(n*log(n)) | No | Yes | Yes |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(n + k) | O(1) | O(1) | Yes | Yes | No |
| Tree Sort | O(n*long(n)) | O(n*long(n)) | O(n*long(n)) | O(n) | O(n*long(n)) | O(1) | No | No | No |
| Heap Sort | O(n*long(n)) | O(n*long(n)) | O(n*long(n)) | O(n) | O(n*long(n)) | O(n*long(n)) | No | Yes | Yes |
| Topo Sort | O(v + e) | O(v + e) | O(v + e) | O(v + e) | O(v + e) | O(1) | No | Yes | No |

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
| pop_back | O(1*) | O(n) | O(1) |
| get_front/end | O(1) | O(1) | O(1) |
| get_at | O(1) | O(n) | O(n) |
| find_key | O(n) | O(n) | O(n) |
| erase_key | O(n) | O(n) | O(n) |

Notes
---

-  Array has better locality
-  Linked Lists are used for storing elements, not searching

# Graph Representations

| Representation | Space Complexity |
| --- | --- |
| Adjacency Matrix | O(v<sup>2</sup>) |
| Adjacency List | O(v + e) | 
| Edge List | O(e) | 

# Find Shortest Path

| Algorithm | Best Time Complexity | Avarage Time Complexity | Worst Time Complexity |  
| --- | --- | --- | --- |
| BFS | O(v + e) | O(v + e) | O(v + e) |
| Dijkstra | O(v + e) | O(e*log(v)) | O((v + e)*log(n)) |
| Bellman-Ford | O(v*e) | O(v*e) | O(v*e) |
| DAG | O(v + e) | O(v + e) | O(v + e) |

# MST

| Algorithm | Time Complexity |
| --- | --- |
| Prim | O(e*log(v)) |
| Kruskal | O(e*log(e)) |  
