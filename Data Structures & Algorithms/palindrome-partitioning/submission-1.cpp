class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

private:
    void dfs(const string& s, int start,
             vector<string>& path, vector<vector<string>>& res) {

        if (start == (int)s.size()) {   // consumed the whole string
            res.push_back(path);
            return;
        }

        for (int end = start; end < (int)s.size(); end++) {
            if (!isPalindrome(s, start, end)) { continue; }

            int len = end - start + 1;
            path.push_back(s.substr(start, len));   // choose
            dfs(s, end + 1, path, res);             // recurse: next piece starts after
            path.pop_back();                        // un-choose
        }
    }

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) { return false; }
            i++;
            j--;
        }
        return true;
    }
};