class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        heapq.heapify(heap)

        for n1 in nums1:
            for n2 in nums2:
                if len(heap) < k:
                    n = [-n1-n2,n1,n2]
                    heapq.heappush(heap,n)

                else:
                    n = heapq.heappop(heap)             
                    if -n1-n2 > n[0]:
                        n = [-n1-n2,n1,n2]
                    heapq.heappush(heap,n)

        res = collections.deque()
        while heap:
            _,x,y = heapq.heappop(heap)
            res.appendleft([x,y])
        
        return res

