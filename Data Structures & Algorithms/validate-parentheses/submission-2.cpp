class Solution {
public:
    bool isValid(string s) {
        string start = "([{";
        stack<char> st;
        for (auto str : s) {
            if (start.find(str) != string::npos) {
                st.push(str);
                continue;
            }
            if (st.empty()) return false;
            switch (st.top()) {
                case '(':
                    if (str != ')') return false;
                    break;
                case '[':
                    if (str != ']') return false;
                    break;
                case '{':
                    if (str != '}') return false;
                    break;
            }
            st.pop();
        }
        return st.empty();
    }
};