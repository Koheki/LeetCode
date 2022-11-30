class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        heapq.heappush(heap,[nums1[0]+nums2[0],0,0])

        n1,n2 = len(nums1),len(nums2)
        res = []
        while heap and k > 0:
            _, i1, i2 = heapq.heappop(heap)

            res.append([nums1[i1],nums2[i2]])
            k -= 1

            if i1 < n1 -1:
                heapq.heappush(heap,[nums1[i1+1]+nums2[i2],i1+1,i2])
            if i1 == 0 and i2 < n2 -1:
                heapq.heappush(heap,[nums1[0]+nums2[i2+1],0,i2+1])

        return res