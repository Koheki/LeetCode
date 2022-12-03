/* Group Anagrams */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> store;

        int idx = 0;
        for (auto s: strs) {
            string cpy = s;
            sort(cpy.begin(), cpy.end());
            auto it = store.find(cpy);
            if (it != store.end()) {
                ret[it->second].push_back(s);
            } else {
                ret.push_back({s});
                store.insert({cpy, idx++});
            }
        }
        return ret;
    }
};
