class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string short_text, long_text;
        if (text1.size() <= text2.size()) {
            short_text = text1;
            long_text = text2;
        } else {
            short_text = text2;
            long_text = text1;
        }
        vector<vector<int>>memo(short_text.size(), vector<int>(long_text.size(), -1));
        return word_finder(short_text, long_text, 0, 0, memo);
    }
    int word_finder(string& sText, string& lText, int si, int li, vector<vector<int>>& memo) {
        if (si == (int)sText.size() || li == (int)lText.size()){
            return 0;
        }
        if (memo[si][li] != -1) {
            return memo[si][li];
        }
        int res = 0;
        if (sText[si] == lText[li]){
            res = 1 + word_finder(sText, lText, si + 1, li + 1, memo); // look for the next matcg
        } else {
                res = max(word_finder(sText, lText, si, li + 1, memo),
                      word_finder(sText, lText, si + 1, li, memo)); 
        }
        return memo[si][li] = res;
    }
};
