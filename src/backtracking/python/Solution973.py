import heapq

class Solution973:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
  
        minheap = []

        for p in points:
            distance =p[0] * p[0] + p[1] * p[1]
            if len(minheap) < k:
                heapq.heappush(minheap, (-distance, p))
            elif -minheap[0][0] > distance:
                heapq.heappop(minheap)
                heapq.heappush(minheap, (-distance, p))

        result = [p[1] for p in minheap]
        return result 
