class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> pieces;
        string cur;
        dfs(s, 0, cur, pieces, res);
        return res;
    }

private:
    void dfs(const string& s, int index, string& cur,
             vector<string>& pieces, vector<vector<string>>& res) {
        if (index == (int)s.size()) {
            if (cur.empty()) {          // nothing left half-built
                res.push_back(pieces);
            }
            return;
        }

        cur.push_back(s[index]);        // choose: this char joins the current piece

        // Branch 1: cut after this char — only legal if the piece is a palindrome
        if (isPalindrome(cur)) {
            string saved = cur;
            pieces.push_back(cur);
            cur.clear();
            dfs(s, index + 1, cur, pieces, res);
            cur = saved;                // un-choose, exact mirror
            pieces.pop_back();
        }

        // Branch 2: don't cut — keep extending
        dfs(s, index + 1, cur, pieces, res);

        cur.pop_back();                 // un-choose
    }

    bool isPalindrome(const string& s) {
        int i = 0;
        int j = (int)s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) { return false; }
            i++;
            j--;
        }
        return true;
    }
};