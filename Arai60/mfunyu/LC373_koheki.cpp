/* Find K Pairs with Smallest Sums */

class Solution {
public:
    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > ret;
        ret.reserve(k);

        typedef pair<int, pair<int, int>> T;
        auto cmp = [](T left, T right) { return left.first > right.first; };
        priority_queue<T, vector<T>, decltype(cmp)> next(cmp);
        next.push({nums1[0] + nums2[0], {0, 0}});

        int len1 = nums1.size();
        int len2 = nums2.size();
        while (k && !next.empty()) {
            auto [i1, i2] = next.top().second;
            next.pop();

            ret.push_back({nums1[i1], nums2[i2]});
            k--;

            if (i1 == 0 && i2 + 1 < len2) {
                next.push({nums1[i1] + nums2[i2 + 1], {i1, i2 + 1}});
            }
            if (i1 + 1 < len1) {
                next.push({nums1[i1 + 1] + nums2[i2], {i1 + 1, i2}});
            }
        }
        return ret;
    }
};
