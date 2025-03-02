import heapq

class Solution215:

    def findKthLargest(self, nums: List[int], k: int) -> int:

        min_heap = []
        for n in nums:
            if len(min_heap) < k :
                heapq.heappush(min_heap, n)
            elif min_heap[0] < n:
                heapq.heappop(min_heap)
                heapq.heappush(min_heap, n)
                
        return heapq.heappop(min_heap)