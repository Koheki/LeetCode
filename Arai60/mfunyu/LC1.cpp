/* Two Sum */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> note;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            auto it = note.find(target - nums[i]);
            if (it != note.end() && it->second != i)
                return {i, it->second};
            note.insert_or_assign(nums[i], i);
        }
        return {};
    }
};
