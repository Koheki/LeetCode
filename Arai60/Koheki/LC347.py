class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        res = []
        Count = collections.defaultdict(int)

        for n in nums:
            Count[n] += 1

        for n,c in sorted(Count.items(),key=lambda x:-x[1])[:k]:
            res.append(n)
        
        return res