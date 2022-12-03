/* Find K Pairs with Smallest Sums */

class Solution {
public:
    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > ret;
        ret.reserve(k);

        typedef pair<int, pair<int, int>> T;
        auto cmp = [](T left, T right) { return left.first > right.first; };
        priority_queue<T, vector<T>, decltype(cmp)> next(cmp);

        int i1 = 0;
        int i2 = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        while (k) {
            if (i2 == 0 && i1 + 1 < len1) {
                next.push({nums1[i1 + 1] + nums2[i2], {i1 + 1, i2}});
            }
            while (k && i2 < len2) {
                if (!next.empty() && next.top().first - nums1[i1] < nums2[i2]) {
                    next.push({nums1[i1] + nums2[i2], {i1, i2}});
                    break;
                }
                ret.push_back({nums1[i1], nums2[i2]});
                k--;
                i2++;
            }
            if (next.empty()) break;
            auto [a1, a2] = next.top().second;
            i1 = a1;
            i2 = a2;
            next.pop();
        }
        return ret;
    }
};
