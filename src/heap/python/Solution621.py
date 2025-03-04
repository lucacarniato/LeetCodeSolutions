import heapq 

import heapq 

class Solution621:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = Counter(tasks)
        max_heap = [-f for f in freq.values()]
        heapq.heapify(max_heap)

        cooldown_queue = []
        time = 0
        while max_heap or cooldown_queue:

            time +=1
            if max_heap:
                task_freq = -heapq.heappop(max_heap)
                if task_freq > 1:
                    cooldown_queue.append((-task_freq +1, time + n))
            
            if cooldown_queue and cooldown_queue[0][1] == time:
                heapq.heappush(max_heap, cooldown_queue.pop(0)[0])
        return time
