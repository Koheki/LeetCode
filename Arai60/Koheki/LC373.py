class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []

        for n1 in nums1:
            if len(heap) >= k and n1 + nums2[0]  > -heap[0][0]:
                break
            for n2 in nums2:
                sm = n1 + n2
                if len(heap) < k:
                    heapq.heappush(heap,[-sm,[n1,n2]])
                elif sm < -heap[0][0]:
                    heapq.heappop(heap)
                    heapq.heappush(heap,[-sm,[n1,n2]])
                else:
                    break

        res = collections.deque()
        while heap:
            _,n = heapq.heappop(heap)
            res.appendleft(n)
        
        return res

