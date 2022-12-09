/* Subarray Sum Equals K
** https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        ++sums[0];

        int ret = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sums.count(sum - k))
                ret += sums[sum - k];
            ++sums[sum];
        }
        return ret;
    }
};
