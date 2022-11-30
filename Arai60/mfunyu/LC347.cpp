/* Top K Frequent Elements */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnts;
        for (auto n: nums) {
            ++cnts[n];
        }

        priority_queue<pair<int, int>> freq;
        for (auto c: cnts) {
            freq.push(make_pair(c.second, c.first));
        }

        vector<int> ret(k);
        for (int i = 0; i < k; i++) {
            ret[i] = freq.top().second;
            freq.pop();
        }
        return ret;
    }
};
