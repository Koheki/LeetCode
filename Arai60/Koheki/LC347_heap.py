class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        count = Counter(nums)
        heap = []
        heapq.heapify(heap)

        for n in count:
            freq = count[n]
            heapq.heappush(heap,(freq,n))

            if len(heap) > k:
                heapq.heappop(heap)

        return [h[1] for h in heap]