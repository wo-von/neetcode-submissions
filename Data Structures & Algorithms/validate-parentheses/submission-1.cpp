class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char>corr = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c: s){
            if (corr.contains(c)){
                if (!st.empty() && st.top() == corr[c]){
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
