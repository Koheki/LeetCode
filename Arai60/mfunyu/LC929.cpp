/* Unique Email Addresses
** https://leetcode.com/problems/unique-email-addresses/description/
*/

class Solution {
public:
    pair<string, string> split(string& str, char c) {
        int pos = str.find(c);
        if (pos != string::npos)
            return {str.substr(0, pos), str.substr(pos)};
        return {str, ""};
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for (auto e: emails) {
            auto [local, domain] = split(e, '@');
            auto [used, ignored] = split(local, '+');
            string str;
            for (auto c: used) {
                if (c != '.') str += c;
            }
            set.insert(str + domain);
        }
        return set.size();
    }
};
