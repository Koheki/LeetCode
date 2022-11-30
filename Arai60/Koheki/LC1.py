class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        twosum = {}
        n = len(nums)

        for i in range(n):
            twosum[target-nums[i]] = i

        for i in range(n):
            if nums[i] in twosum and twosum[nums[i]] != i:
                return [twosum[nums[i]],i]