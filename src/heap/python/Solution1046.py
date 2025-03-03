import heapq

class Solution:
    
    def lastStoneWeight(self, stones: List[int]) -> int:

        max_heap = []
        for s in stones:
            heapq.heappush(max_heap, -s)
        
        while len(max_heap) > 1:

            first_max = -heapq.heappop(max_heap)
            second_max = -heapq.heappop(max_heap)
            diff = first_max - second_max 

            if diff > 0:
                heapq.heappush(max_heap, -diff)

        return -max_heap[0] if max_heap else 0