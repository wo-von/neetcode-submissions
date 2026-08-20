class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> pieces;
        dfs(s, res, pieces, 0);
        return res;
    }
    void dfs(string& s, vector<vector<string>>& res, vector<string>& pieces, int index) {
        if (index == s.size()){
            res.push_back(pieces);
            return;
        }
        int start = index;
        for (int j = start; j < s.size(); j++) {
            int length = j - start + 1;
            string piece = s.substr(start, length);
            if (isPalindrome(piece)) { // take it
                pieces.push_back(piece);
                dfs(s, res, pieces, j + 1);
                pieces.pop_back();
            }
        }
    }
    bool isPalindrome(const string& s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) { return false; }
            i++;
            j--;
        }
        return true;
    }

};
