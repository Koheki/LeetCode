/* Valid Parentheses */

class Solution {
public:
    bool isValid(string s) {
        stack<char> ord;
        for(auto c : s) {
            if (c == '(') {
                ord.push(')');
            } else if (c == '{') {
                ord.push('}');
            } else if (c == '[') {
                ord.push(']');
            } else {
                if (ord.empty() || ord.top() != c)
                    return false;
                ord.pop();
            }
        }
        return ord.size() == 0;
    }
};
