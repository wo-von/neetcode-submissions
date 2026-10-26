class Solution {
public:
    void paren_backtrack(vector<string>& res, int to_open, int to_close,
        string& this_member){
        if (to_open == 0 && to_close == 0) {
            res.push_back(this_member);
            return;
        }
        if (to_open){
            this_member.push_back('(');
            paren_backtrack(res, to_open - 1, to_close + 1, this_member);
            this_member.pop_back();
        }
        if (to_close){
            this_member.push_back(')');
            paren_backtrack(res, to_open, to_close - 1, this_member);
            this_member.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int to_open = n, to_close = 0;
        string this_member = "";
        paren_backtrack(res, to_open, to_close, this_member);
        return res;
    }
};
