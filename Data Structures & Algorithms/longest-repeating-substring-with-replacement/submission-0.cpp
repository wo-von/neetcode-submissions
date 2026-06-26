class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            unordered_map<char, int> count;
            int mmax = 0;
            for (int j = i; j < s.size(); j++){
                count[s[j]]++;
                mmax = max(mmax, count[s[j]]);
                if (k >= j - i +1 - mmax )
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
