import heapq
class MedianFinder:

    def __init__(self):
        self._maxheap = []
        self._minheap = []
        
    def addNum(self, num: int) -> None:

        if self._maxheap and num > -self._maxheap[0]:
            heapq.heappush(self._minheap, num)
        else:
            heapq.heappush(self._maxheap, -num)

        # rebalance the heaps
        if len(self._maxheap) > len(self._minheap) + 1:
            val = -heapq.heappop(self._maxheap)
            heapq.heappush(self._minheap, val)
        elif len(self._minheap) > len(self._maxheap) + 1:
            val = heapq.heappop(self._minheap)
            heapq.heappush(self._maxheap, -val)

    def findMedian(self) -> float:

        len_min_heap = len(self._minheap)
        len_max_heap = len(self._maxheap)


        if len_max_heap == len_min_heap:
            return (-self._maxheap[0] + self._minheap[0]) * 0.5
        elif len_max_heap > len_min_heap:
            return -self._maxheap[0] 
        else:
            return self._minheap[0] 