class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)

        cal = [0]*(n+1)
        caln = collections.defaultdict(int)
        caln[0] += 1
        res = 0
        for i in range(1,n+1):
            cal[i] = nums[i-1] + cal[i-1]
            if cal[i] - k in caln:
                res += caln[cal[i]-k]
            caln[cal[i]] += 1

        return res