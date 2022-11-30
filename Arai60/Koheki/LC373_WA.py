class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        l1,l2 = 0,0
        n1,n2 = len(nums1)-1,len(nums2)-1
        res = [[nums1[0],nums2[0]]]
        k -= 1
        while k > 0 and (l1 <= n1 or l2 <= n2):
            t1 = l1+1 if l1 < n1 else n1
            t2 = l2+1 if l2 < n2 else n2

            if l1 <= n1 and l2 <= n2:
                if nums1[l1] + nums2[t2] < nums1[t2] + nums2[l2]:
                    res.append([nums1[l1],nums2[t2]])
                    l2 += 1
                else:
                    res.append([nums1[t1],nums2[l2]])
                    l1 += 1

            elif l1 <= n1:
                res.append([nums1[t1],nums2[t2]])
                l1 += 1
            else:
                res.append([nums1[t1],nums2[t2]])
                l2 += 1

            k -= 1

        return res
