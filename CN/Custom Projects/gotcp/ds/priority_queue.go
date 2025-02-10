package ds

// Item represents an element in the priority queue.
type Item struct {
	Value uint16 // Value of the item
	index int    // Index of the item in the heap (needed for heap operations)
}

// PriorityQueue implements heap.Interface.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// Lower value means higher priority
	return pq[i].Value > pq[j].Value
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x any) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // Allow GC to reclaim memory
	item.index = -1 // Mark as removed
	*pq = old[:n-1]
	return item
}

func InitPq(size uint16) (pq PriorityQueue) {
	for i := range size {
		item := Item{
			Value: i,
		}
		pq.Push(&item)
	}
	return
}
