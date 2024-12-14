# Cache Memory

CPU-Memory Bottleneck
-

- Performance of high-speed computers is usually limited by memory bandwidth and latency
  - Latency (time for a single access)
    - Physical size affects latency
  - Bandwidth (number of accesses per unit time)

Multilevel Memory
-

- Reduce average latency using small, fast memories called caches.
  - Caches are a mechanism to reduce memory latency
  - *Cache hit* and *Cache miss*
- SRAM - Small, fast memory
- DRAM - Big, slow memory (main memory)
- Types of caches
  - Fully Associative
  - Set Associative
  - Direct Mapped
- Write-back
  - Doesn't wait after writing in register, data loss may ocurr
- Write-through
  - Writes data as write-back but waits the data to be saved on the disk, much safer
- Prefetching
  - Refers to the retrieving and storing of data into the buffer memory (cache) before the processor requires the data 
  
