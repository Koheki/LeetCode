/* Intersection of Two Arrays */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> ret;

        for (auto s: set1) {
            if (set2.count(s)) ret.push_back(s);
        }
        return ret;
    }
};
