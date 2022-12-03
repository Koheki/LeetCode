/* Group Anagrams */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> store;

        int idx = 0;
        for (auto s: strs) {
            vector<int> key(26);
            for (auto c: s) ++key[c - 'a'];
            string str;
            for (auto k: key) {
                str += to_string(k) + ',';
            }
            auto it = store.find(str);
            if (it != store.end()) {
                ret[it->second].push_back(s);
            } else {
                ret.push_back({s});
                store.insert({str, idx++});
            }
        }
        return ret;
    }
};
