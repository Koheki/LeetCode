/* 387. First Unique Character in a String
** https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        for (auto c: s) {
            ++cnt[c];
        }
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (cnt[s[i]] == 1)
                return i;
        }
        return -1;
   }
};
